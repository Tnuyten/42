#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <sstream>
#include <iostream>

class Data {
	private:
		int			dataInt;
		std::string	dataString;
	public:
		//OCCF
		Data();
		Data(const Data& other);
		~Data();
		Data& operator=(const Data& other);
		
		// Other constructors
		Data(int di, std::string ds);

		// Getters
		int getDataInt() const;
		std::string getDataString() const;

		// Setters
		void setDataInt(int num);
		void setDataString(std::string str);

		// toString
		std::string toString() const;

		// Public functions
		void trunc_string_len();
};

std::ostream& operator<<(std::ostream& os, const Data& d);

#endif
