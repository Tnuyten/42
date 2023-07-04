#include "Data.hpp"

#define STR_MAX_LEN sizeof(uintptr_t) - sizeof(int)

Data::Data()
{
	this->dataInt = 2147483647;
	this->dataString = std::string("OP");
	this->trunc_string_len();
	std::cout << "Default constructor" << std::endl;
}

Data::Data(const Data &other)
{
	this->dataInt = other.dataInt;
	this->dataString = other.dataString;
	this->trunc_string_len();
}

Data::~Data() {}

Data &Data::operator=(const Data &other)
{
	if(this != &other) {
		this->dataInt = other.dataInt;
		this->dataString = other.dataString;
		this->trunc_string_len();
	}
	return *this;
}

Data::Data(int di, std::string ds)
{
	this->dataInt = di;
	this->dataString = ds;
	this->trunc_string_len();
	std::cout << "Parameterized constructor" << std::endl;
}

int Data::getDataInt() const
{
	return this->dataInt;
}

std::string Data::getDataString() const
{
	return this->dataString;
}

void Data::setDataInt(int num)
{
	this->dataInt = num;
}

void Data::setDataString(std::string str)
{
	this->dataString = str;
	this->trunc_string_len();
}

std::string Data::toString() const
{
	std::stringstream ss;
	ss << "Data[dataInt: " << this->getDataInt() << ", dataString: " << this->getDataString() << "]";
	return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Data& d) {
	return os << d.toString();
}

void Data::trunc_string_len() {
	if (this->dataString.length() > STR_MAX_LEN)
		this->dataString = this->dataString.substr(0, STR_MAX_LEN);
}