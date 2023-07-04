#include "RobotomyRequestForm.hpp"

// OCCF
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", RRF_SIGN_REQ, RRF_EXEQ_REQ, "") {
	std::cout << this->getName() << " constructed with no target (Basically unusable, but required)" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << this->getName() << " deconstructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade(), other.getTarget()) {
	std::cout << this->getName() << " copy constructed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		std::cout	<< "RobotomyRequestForm: No meaningful object properties can be copied. " << std::endl;
	}
	return *this;
}

// Other constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", RRF_SIGN_REQ, RRF_EXEQ_REQ, target) {
	std::cout << "Constructed " << this->getName() << " with target: " << target << std::endl;
}

// Public functions
void RobotomyRequestForm::execute(Bureaucrat const &b) const {
	AForm::execute(b);
	srand(time(0));
	std::cout << "BRRRRZZZZRRRRT..." << std::endl;
	std::cout << "BRRRRWAAAAAAAP..." << std::endl;
	std::cout << "BRRRRZZZZRRREE..." << std::endl;

	if (rand() % 2 == 0) {
		std::cout << "Robotomy failed" << std::endl;
		return;
	}
	std::cout << "GGGRRRRREEEEEE..." << std::endl;
	std::cout << "BRRBRRBRBRRBRR..." << std::endl;
	std::cout << "Successfully robotomized target " << this->getTarget() << std::endl;
}

// Private functions
AForm* RobotomyRequestForm::create(const std::string& target) {
		return new RobotomyRequestForm(target);
}