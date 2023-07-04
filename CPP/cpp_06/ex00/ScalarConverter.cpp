#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Constructing ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
	std::cout << "Copy constructing ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Deconstructed" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	if(this != &other)
	{

	}
	return *this;
}

double ScalarConverter::convert(std::string input) {
	if(input.size() <= 0)
		throw std::invalid_argument("String is empty");
	if(is_special(input))
	{
		if(is_inff(input)) {
			throw std::domain_error(input.substr(0, 5));
		}
		if(is_inf(input) || is_nanf(input)) {
			throw std::domain_error(input.substr(0, 4));
		}
		if(is_nand(input)) {
			throw std::domain_error(input.substr(0, 3));
		}
	}
	if(is_char_literal(input)) {
		return input[0];
	}
	if(is_valid_number(input)) {
		std::stringstream ss(input);
		double d;
		ss >> d;
		return d;
	}
	throw std::invalid_argument("Input is not a valid number, char literal, or special value");
}

bool is_valid_number(std::string input) {
	size_t i = 0;
	if(input[i] == '-')
		i++;
	while(isdigit(input[i]))
		i++;
	if(input[i] == '\0')
		return true;
	if(input[i] == '.')
		i++;
	while(isdigit(input[i]))
		i++;
	if(input[i] == '\0')
		return true;
	return false;
}

bool is_char_literal(std::string input) {
	if(isprint(input[0]) && !isdigit(input[0])) {
		if(input[1] == '\0')
			return true;
	}
	return false;
}

bool is_special(std::string str) {
	return is_inff(str) || is_inf(str) || is_nan(str);
}

bool is_inff(std::string str) {
	return is_inffp(str) || is_inffn(str);
}
bool is_inffp(std::string str) {
	if(str.size() == 0)
		return 0;
	if(str == "+inff")
		return 1;
	return 0;
}
bool is_inffn(std::string str) {
	if(str.size() == 0)
		return 0;
	if(str == "-inff")
		return 1;
	return 0;
}

bool is_inf(std::string str) {
	return is_infp(str) || is_infn(str);
}
bool is_infp(std::string str) {
	if(str.size() == 0)
		return 0;
	if(str == "+inf")
		return 1;
	return 0;
}
bool is_infn(std::string str) {
	if(str.size() == 0)
		return 0;
	if(str == "-inf")
		return 1;
	return 0;
}

bool is_nan(std::string str) {
	return is_nand(str) || is_nanf(str);
}
bool is_nand(std::string str) {
	if(str.size() == 0)
		return 0;
	if(!isalpha(str[0]))
		return 0;
	if(str == "nan")
		return 1;
	return 0;
}
bool is_nanf(std::string str) {
	if(str.size() == 0)
		return 0;
	if(!isalpha(str[0]))
		return 0;
	if(str == "nanf")
		return 1;
	return 0;
}