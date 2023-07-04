#include "Intern.hpp"

// OCCF
Intern::Intern() {
	std::cout << "Constructed Intern" << std::endl;
}

Intern::Intern(const Intern &) {
	std::cout << "Copy Constructed Intern" << std::endl;
}

Intern::~Intern() {
	std::cout << "Destroyed Intern" << std::endl;
}

Intern& Intern::operator=(const Intern &) {
	std::cout << "Intern assigned with operator=" << std::endl;
	return *this;
}

// Public functions
AForm* Intern::makeForm(std::string name, std::string target) {
	typedef AForm* (*formCreator)(std::string const &target);

	static formCreator factory[3] = {
		ShrubberyCreationForm::create,
		RobotomyRequestForm::create,
		PresidentialPardonForm::create 
	};
	static std::string formNames[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	
	for(int i = 0; i < 3; i++)
	{
		if(name == formNames[i])
		{
			std::cout << "Intern creating form " << name << std::endl;
			return factory[i](target);
		}
	}
	throw Intern::FormDoesNotExistException(name);
}

//Exception classes
	// Exception constructors
	Intern::FormDoesNotExistException::FormDoesNotExistException(std::string name)
	{
		std::stringstream ss;
		ss	<< "Intern::FormDoesNotExistException: Cannot create form " << name << ", no such form on record";
		this->message = ss.str();
	}

	// Exception Public functions
	const char* Intern::FormDoesNotExistException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	Intern::FormDoesNotExistException::~FormDoesNotExistException() _NOEXCEPT {}