#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define SCF_SIGN_REQ 145
#define SCF_EXEQ_REQ 137

class ShrubberyCreationForm : public AForm {
	public:
		// OCCF
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		// Other constructors
		ShrubberyCreationForm(std::string target);

		// Public function
		void execute(Bureaucrat const& b) const;
};

#endif