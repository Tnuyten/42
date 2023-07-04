#include "ScalarConverter.hpp"

#include <cfloat>
#include <cmath>

void display_char(double d) {
	char c = (char)d;
	std::cout << "char: ";
	if (d > CHAR_MAX || d < 0)
		std::cout << "Impossible";
	else if(isprint(c)) {
		std::cout << c;
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

void display_int(double d) {
	int c = (int)d;
	std::cout << "int: ";
	if(d > INT_MAX || d < INT_MIN) {
		std::cout << "Impossible";
	}
	else 
		std::cout << c;
	std::cout << std::endl;
}

void display_float(double d) {
	float f = (float)d;
	float intpart = floor(d);
	float fracpart = d - intpart;

	std::cout << "float: ";
	if(d > FLT_MAX || d < -FLT_MAX || (fracpart > 0 && fracpart - FLT_MIN < 0) || (fracpart < 0 && fracpart + FLT_MIN > 0)) {
		std::cout << "Impossible" << std::endl;
		return ;
	}
	std::cout << f << "f" << std::endl;
}

void display_double(double d) {
	std::cout << "double: " << d << std::endl;
}

std::string convert_err(std::string err, int type) {
	if (type == 0 && (is_nand(err) || is_infn(err) || is_infp(err)))
		return err + "f";
	if (type == 1 && (is_nanf(err) || is_inffn(err) || is_inffp(err))) {
		return err.substr(0, err.size() - 1);
	}
	return err;
}

void display_error(std::string err, int type) {
	switch(type) {
		case 0:
			if(is_inffp(err) || is_inffn(err) || is_nanf(err))
				std::cout << err << std::endl;
			else
				std::cout << convert_err(err, 0) << std::endl;
			break;
		case 1:
			if(is_infp(err) || is_infn(err) || is_nand(err))
					std::cout << err << std::endl;
			else
				std::cout << convert_err(err, 1) << std::endl;
			break;
		default:
			std::cout << "Impossible" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Please enter one argument max" << std::endl;
		return 1;
	}
	std::cout << std::fixed;
	std::string input(argv[1]);
	std::cout << "Input: [" << input << "]" << std::endl;

	try {
		double converted = ScalarConverter::convert(input);
		display_char(converted);
		display_int(converted);
		display_float(converted);
		display_double(converted);
	}
	catch (std::domain_error& e) {
		std::cout << "char: "; display_error(e.what(), -1);
		std::cout << "int: "; display_error(e.what(), -1);
		std::cout << "float: "; display_error(e.what(), 0);
		std::cout << "double: "; display_error(e.what(), 1);
	}
	catch (std::invalid_argument& e) {
		std::cout << "Invalid argument: " << e.what() << std::endl;
	}
}