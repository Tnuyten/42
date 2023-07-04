#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define PPF_SIGN_REQ 25
#define PPF_EXEQ_REQ 5

class AForm;

class PresidentialPardonForm : public AForm {
	public:
		// OCCF
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		// Other constructors
		PresidentialPardonForm(std::string target);

		// Public functions
		void execute(Bureaucrat const& b) const;

		// Private functions
		static AForm* create(const std::string& target) ;
};

#endif