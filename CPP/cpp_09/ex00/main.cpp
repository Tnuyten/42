/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:32:09 by tnuyten           #+#    #+#             */
/*   Updated: 2023/09/15 19:56:06 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

using std::vector;
using std::pair;

using std::getline;
using std::stof;

void readfile(vector<pair<string, double>>& db, string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error opening input file. Does it have permissions?" << endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	getline(file, line); // skip first entry of input
	while (getline(file, line)) {
		size_t comma = line.find(",");
		size_t pipe = line.find("|");

		bool neither = comma == string::npos && pipe == string::npos;
		bool both = comma != string::npos && pipe != string::npos;

		string date;
		double value;
		if (neither || both) {
			date = "";
			value = 0.f;
		} else if (comma != string::npos || pipe != string::npos) {
			size_t delimiterpos = comma != string::npos ? comma : pipe;
			date = line.substr(0, delimiterpos);
			try {
				value = stof(line.substr(delimiterpos + 1));
			}
			catch (const std::exception& e) {
				date = "Conversion error: check your input values.";
			}
		}
		db.push_back(std::make_pair(date, value));
	}

	file.close();
}

int validate_date(string date) {
	size_t first = date.find("-");
	size_t second = date.rfind("-");

	if (first == second || first == string::npos || second == string::npos)
		return false;

	int year = stoi(date.substr(0, first)); // Caught in calling function
	int month = stoi(date.substr(first + 1, second));
	int day = stoi(date.substr(second + 1));

	// std::cout << "Day: " << day << ". Month: " << month << ". Year: " << year << endl;

	if (year <= 2008 || year > 9999)
		return false;
	if (month <= 0 || month > 12)
		return false;
	if (day <= 0 || day > 31)
		return false;

	return true;
}

int validate_double(double value) {
	if (value < 0) {
		cout << "Error: not a positive number" << endl;
		return false;
	}
	if (value > 1000) {
		cout << "Error: Value is too large" << endl;
		return false;
	}
	return true;
}

int compare(pair<string, double> lhs, pair<string, double> rhs) {
	return lhs.first < rhs.first;
}

double value_of_nearest_date(string date, vector<pair<string, double>> db) {
	auto it = lower_bound(db.begin(), db.end(), make_pair(date, 0.f), compare);

	if (it == db.begin() || it->first == date)
		return it->second;

	--it; // move one back as the lower_bound function finds the next instead of the previous entry if it doesn't find an exact match.

	return it->second;
}

void result(vector<pair<string, double>> db, vector<pair<string, double>> input) {
	for (const auto& item: input) {
		if (item.first == "Conversion error: check your input values.") {
			cout << item.first << endl;
			continue;
		}
		if (item.first == "") {
			cout << "Error: Line is malformed" << endl;
			continue;
		}
		try {
			if (validate_date(item.first) == false) {
				cout << "Error: Invalid date" << endl;
				continue;
			}
		} catch (const std::invalid_argument& e) {
			cout << "Error: Date malformed" << endl;
			continue;
		}
		if (validate_double(item.second) == false) {
			continue;
		}
		double val = value_of_nearest_date(item.first, db);
		cout << item.first << "=> " << item.second << " = " << val * item.second << endl;
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cerr << "Usage: ./btc [filename]" << endl;
		return 1;
	}

	try {
		string filename(argv[1]);

		if (filename.length() == 0) {
			cerr << "Input file has no name" << endl;
			return 1;
		}
		vector<pair<string, double>> db;
		vector<pair<string, double>> input;

		readfile(db, string("data.csv"));
		readfile(input, filename);
		result(db, input);
	} catch (const std::bad_alloc& e) {
		cout << "Allocation Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}