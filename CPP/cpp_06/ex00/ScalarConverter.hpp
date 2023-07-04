#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {
	private:
		//OCCF
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static double convert(std::string str);
};

bool is_special(std::string str);
bool is_inff(std::string str);
bool is_inffp(std::string str);
bool is_inffn(std::string str);
bool is_inf(std::string str);
bool is_infp(std::string str);
bool is_infn(std::string str);
bool is_nan(std::string str);
bool is_nand(std::string str);
bool is_nanf(std::string str);
bool is_valid_number(std::string input);
bool is_char_literal(std::string input);

#endif