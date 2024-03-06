/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:00:46 by tnuyten           #+#    #+#             */
/*   Updated: 2023/09/15 20:59:45 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::stof;

#include <cctype>
using std::isdigit;

#include <utility>
using std::pair;
using std::make_pair;

#include <algorithm>
using std::for_each;
using std::swap;
using std::sort;
using std::lower_bound;

#include <iterator>
using std::next;
using std::advance;
using std::back_inserter;
using std::inserter;

#include <type_traits>
using std::is_same;
using std::enable_if;
using std::random_access_iterator_tag;

/*##################################*/
/*									*/
/*				Misc				*/
/*									*/
/*##################################*/

int validate_entry(const string entry) {
	int num;
	for (const auto& el : entry) {
		if (!isdigit(el) && !isspace(el)) {
			cout << "Error: Invalid argument: NaN" << endl;
			exit(EXIT_FAILURE);
		}
	}
	try {
		num = stoi(entry);
	}
	catch (std::invalid_argument e) {
		cout << "Error: Invalid argument: " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (std::out_of_range e) {
		cout << "Error: Invalid argument: Number is too large or too small" << endl;
		exit(EXIT_FAILURE);
	}
	if (num == 0) {
		cout << "Error: Invalid argument: Zero is not a positive number" << endl;
		exit(EXIT_FAILURE);
	}
	return num;
}


template <typename Container>
typename enable_if<is_same<typename Container::iterator::iterator_category, random_access_iterator_tag>::value>::type
sortContainer(Container& container) {
	sort(container.begin(), container.end());
}

template <typename Container>
typename enable_if<!is_same<typename Container::iterator::iterator_category, random_access_iterator_tag>::value>::type
sortContainer(Container& container) {
	container.sort();
}

template <template <typename...> class Container>
void print_container(Container<int> nums, string optcstr = "") {
	auto it = nums.begin();
	cout << optcstr;
	while (it != nums.end()) {
		cout << *it;
		it++;
		if (it != nums.end())
			cout << " - ";
	}
	cout << endl;
}

/*##################################*/
/*									*/
/*				Algorithm			*/
/*									*/
/*##################################*/

// Generate a list of indices for the pend numbers up to and including N. e.g. 0 1 3 2 5 4 11 10 9 8 7 6 21 20 19 etc...
template <template <typename ...> class Container>
void generate_jacobsthal(Container<int>& con, int n) {
	Container<int> jacob = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,\
							10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, \
							2796203, 5592405, 11184811, 22369621, 44739243, 89478485, \
							178956971, 357913941, 715827883, 1431655765};
	int previous_jacob = 0;
	con.clear();
	for (int i = 0; i <= n; ) {
		back_inserter(con) = i;
		for (int j = i - 1; j > previous_jacob; j--) {
			back_inserter(con) = j;
		}
		previous_jacob = i;
		i = *next(find(jacob.begin(), jacob.end(), i)); // Get the next number from the jacobsthal list.

		// Generate the last few remaining numbers that would otherwise be skipped on the last iteration.
		// (e.g. if we want the numbers up to 15, without this code the generator would stop at 11, as i jumps to 21)
		if (i > n) { 
			for (int j = n; j > previous_jacob; j--) {
				back_inserter(con) = j;
			}
		}
	}
}

template <typename InputIt, template <typename...> class Container> //HELP
void makePairs(InputIt first, InputIt last, Container<pair<int, int>>& result) {
	while (first != last) {
		pair<int, int> p;
		p.first = *first;
		first++;
		if (first != last) {
			p.second = *first;
			first++;
		}
		else {
			p.second = -1;
		}
		back_inserter(result) = p;
	}
}

void pairSort(pair<int, int>& p) {
	if (p.first < p.second) {
		swap(p.first, p.second);
	}
}

template <template <typename...> class Container>
void mergesort(Container<pair<int, int>>& con) {
	if (con.size() > 1) {
		Container<pair<int, int>> left, right;
		auto middle = con.begin(); advance(middle, con.size() / 2);

		std::copy(con.begin(), middle, back_inserter(left));
		std::copy(middle, con.end(), back_inserter(right));

		con.clear();

		mergesort(left);
		mergesort(right);

		auto leftit = left.begin();
		auto rightit = right.begin();

		while (leftit != left.end() && rightit != right.end()) {
			if (leftit->first < rightit->first) {
				con.push_back(*leftit++);
			} else {
				con.push_back(*rightit++);
			}
		}
		while (leftit != left.end()) {
			con.push_back(*leftit++);
		}
		while (rightit != right.end()) {
			con.push_back(*rightit++);
		}
	}
}

// Sort the given container of ints with the ford-johnson algorithm.
template <template <typename...> class Container>
Container<int> ford_johnson(Container<int> nums) {
	// Use the given container to make a new container of pairs, and sort the pair elements.
	Container<pair<int, int>> pairs;
	makePairs(nums.begin(), nums.end(), pairs);
	for_each(pairs.begin(), pairs.end(), pairSort);

	// If the last number went unpaired, take it out and save it for later. 
	pair<int, int> last = make_pair(-1, -1);
	if (pairs.back().second == -1) { // -1 is just a flag to show it's unpaired.
		last = pairs.back();
		pairs.pop_back();
	}
	// Sort the pairs.
	// sortContainer(pairs); 
	mergesort(pairs); //better?

	// Build the main chain from the larger number of each pair.
	Container<int> main_chain;
	for (const auto& p : pairs) {
		back_inserter(main_chain) = p.first;
	}

	// Generate a container of indices for the pairs that denote the order in which they're processed. 
	Container<int> indices = {};
	generate_jacobsthal(indices, pairs.size() - 1);

	// Insert the pending numbers into the main chain using binary search, by the jacobsthal ordering.
	for (int ind : indices) {
		typename Container<pair<int, int>>::iterator it = pairs.begin(); advance(it, ind);
		pair<int, int> current_pair = *it;
		typename Container<int>::iterator current_main_chain_pos = find(main_chain.begin(), main_chain.end(), current_pair.first);
		
		if (current_main_chain_pos != main_chain.begin()) {
			auto target_position = lower_bound(main_chain.begin(), current_main_chain_pos, current_pair.second);
			main_chain.emplace(target_position, current_pair.second);
		}
		else
			inserter(main_chain, main_chain.begin()) = current_pair.second;
	}

	// Almost done, we still need to add the possible unpaired number.
	// Using binary search to find its position in the chain. 
	if (last.first != -1) {
		auto target_position = lower_bound(main_chain.begin(), main_chain.end(), last.first);
		main_chain.emplace(target_position, last.first);
	}

	return main_chain;
}

/*##################################*/
/*									*/
/*		  Identify Container		*/
/*									*/
/*##################################*/

// Including these here because they're not used above!
#include <list>
using std::list;

#include <deque>
using std::deque;

// #include <vector>
// using std::vector; //optional and possible, but forbidden by the earlier use in ex00. Including it anyways because it's extra. 

template <typename T>
string identifyContainerType([[maybe_unused]]const T& container) {
	// if (is_same<T, vector<typename T::value_type, typename T::allocator_type>>::value) {
	// 	return "std::vector";
	// } else 
	if (is_same<T, list<typename T::value_type, typename T::allocator_type>>::value) {
		return "std::list";
	} else if (is_same<T, deque<typename T::value_type, typename T::allocator_type>>::value){
		return "std::deque";
	}
	return "Unknown container";
}

/*##################################*/
/*									*/
/*				Time				*/
/*									*/
/*##################################*/

#include <chrono>
using hrc = std::chrono::high_resolution_clock;
using us = std::chrono::microseconds;
template <typename ToDuration, typename FromDuration> // The things you have to do to get rid of "std::" sometimes...
ToDuration shortened_duration_cast(const FromDuration& d) {
	return std::chrono::duration_cast<ToDuration>(d);
}

template <template <typename...> class Container>
void time_and_display(const Container<int> con) {
	print_container(con, "Before: ");

	auto start = hrc::now(); // Time the algorithm.
	Container<int> result = ford_johnson(con);
	auto end = hrc::now();

	cout << "After : ";
	print_container(result);

	auto duration = shortened_duration_cast<us>(end - start);
	cout << "Time to process a range of " << con.size() << " elements with " << identifyContainerType(con) << ": " << duration.count() << "μs" << endl;
}

/*##################################*/
/*									*/
/*				Main				*/
/*									*/
/*##################################*/

int main(int argc, char** argv) {
	if (argc <= 1) {
		cout << "Usage: ./PmergeMe *[int > 0]" << endl;
		exit(EXIT_FAILURE);
	}

	// Validate the user input and make a list/dequeue/vector of the numbers-to-be-sorted.
	deque<int> deq_nums;
	list<int> lst_nums;
	// vector<int> vec_nums;

	for (int i = 1; i < argc; i++) {
		int val = validate_entry(argv[i]);
		back_inserter(deq_nums) = val;
	}

	std::copy(deq_nums.begin(), deq_nums.end(), back_inserter(lst_nums));
	// std::copy(deq_nums.begin(), deq_nums.end(), back_inserter(vec_nums));

	time_and_display(deq_nums); cout << endl;
	time_and_display(lst_nums); //cout << endl;
	// time_and_display(vec_nums);
}
