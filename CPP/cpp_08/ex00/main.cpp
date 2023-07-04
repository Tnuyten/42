#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

int main() {
	// Container tests
	{
		// vector tests
		{
			std::cout << "Vector tests: " << std::endl;
			std::vector<int> vec;

			vec.push_back(10);
			vec.push_back(11);
			vec.push_back(12);

			auto it1 = easyfind(vec, 11);
			std::vector<int>::iterator it2 = easyfind(vec, 9);

			if (it1 != vec.end())
				std::cout << "Value of it1: " << *it1 << std::endl;
			else
				std::cout << "it1 == end" << std::endl;

			if (it2 != vec.end())
				std::cout << "Value of it2: " << *it2 << std::endl;
			else
				std::cout << "it2 == end" << std::endl;

			vec.clear();
			std::vector<int>::iterator empty = easyfind(vec, 123);

			if (empty != vec.end())
				std::cout << "Value of empty: " << *empty << std::endl;
			else
				std::cout << "empty == end" << std::endl;
		}

		// list test
		{
			std::list<int> lst;

			lst.push_back(21);
			lst.push_back(22);
			lst.push_back(23);

			std::list<int>::iterator it1 = easyfind(lst, 21);
			std::list<int>::iterator it2 = easyfind(lst, -1);

			if (it1 != lst.end())
				std::cout << "Exists: " << *it1 << std::endl;
			else
				std::cout << "it1 == empty" << std::endl;

			if (it2 != lst.end())
				std::cout << "Doesn't exist: " << *it2 << std::endl;
			else
				std::cout << "it2 == empty" << std::endl;
		}
	// set test (associative container)
		{
			std::set<int> s;

			s.insert(123);
			s.insert(234);
			s.insert(345);

			std::cout << "Set: " << *easyfind(s, 234) << std::endl;

		}
	}

	// Non-container tests
	{
		// Array test
		{
			// int arr[5] = {5,7,6,2,9};
			// easyfind(arr, 7); // compiler error
		}
	}

}