#include "PresidentialPardonForm.hpp"

// OCCF
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", PPF_SIGN_REQ, PPF_EXEQ_REQ, "") {
	std::cout << this->getName() << " constructed with no target (Basically unusable, but required)" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << this->getName() << " deconstructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade(), other.getTarget()) {
	std::cout << this->getName() << " copy constructed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		std::cout	<< "PresidentialPardonForm: No meaningful object properties can be copied. " << std::endl;
	}
	return *this;
}

// Other constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", PPF_SIGN_REQ, PPF_EXEQ_REQ, target) {
	std::cout << "Constructed " << this->getName() << " with target: " << target << std::endl;
}

// Public functions
void PresidentialPardonForm::execute(Bureaucrat const &b) const {
	AForm::execute(b);
	std::cout << this->getTarget() << " has been pardoned by Zaphod BeebleBrox" << std::endl;
}

// Private functions
AForm* PresidentialPardonForm::create(const std::string& target) {
		return new PresidentialPardonForm(target);
}