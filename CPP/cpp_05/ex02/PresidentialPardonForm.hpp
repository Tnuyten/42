#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define PPF_SIGN_REQ 25
#define PPF_EXEQ_REQ 5

class PresidentialPardonForm : public AForm {
	public:
		// OCCF
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		// Other constructors
		PresidentialPardonForm(std::string target);

		// Public function
		void execute(Bureaucrat const& b) const;
};

#endif