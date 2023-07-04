#include <iostream>
#include <fstream>

std::string replace(std::string line, std::string match, std::string rep) {
	size_t i = 0;
	std::string ret = "";
	while(i < line.size()) {
		if (line.compare(i, match.size(), match) == 0) {
			ret += rep;
			i += match.size();
		}
		else
			ret += line[i++];
	}
	return ret;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./notsed filename match replace" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string match = argv[2];
	std::string rep = argv[3];
	if (filename.size() <= 0) {
		std::cout << "Filename cannot be empty." << std::endl;
		return 1;
	}
	if (match.size() <= 0) {
		std::cout << "match string cannot be empty." << std::endl;
		return 1;
	}

	std::fstream infile(filename);
	if (!infile.is_open() || !infile.good() || infile.eof() || infile.fail()) {
		std::cout << "Error opening infile." << std::endl;
		return 1;
	}
	std::ofstream outfile(filename + ".replace", std::ios::out | std::ios::trunc);
	if (!outfile.is_open() || !infile.good()) {
		std::cout << "Error opening outfile." << std::endl;
		return 1;
	}

	std::string line;
	while(!infile.eof() && !infile.fail()) {
		getline(infile, line);
		if (line.size() != 0)
			outfile << replace(line, match, rep) << "\n";
	}

	infile.close();
	outfile.close();
	return 0;
}

