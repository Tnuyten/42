#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define RRF_SIGN_REQ 72
#define RRF_EXEQ_REQ 45

class RobotomyRequestForm : public AForm {
	public:
		// OCCF
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		// Other constructors
		RobotomyRequestForm(std::string target);

		// Public functions
		void execute(Bureaucrat const& b) const;
};

#endif