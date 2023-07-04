#ifndef INTERN_CPP
#define INTERN_CPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// The fuck does this exercise have to do with exceptions??

class Intern {
	public:
		// OCCF
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string name, std::string target);

		class FormDoesNotExistException : std::exception {
			private:
				std::string message;
			public:
				FormDoesNotExistException(std::string name);
				virtual ~FormDoesNotExistException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
};

#endif