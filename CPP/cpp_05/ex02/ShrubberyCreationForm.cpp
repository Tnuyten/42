#include "ShrubberyCreationForm.hpp"

// OCCF
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SCF_SIGN_REQ, SCF_EXEQ_REQ, "") {
	std::cout << this->getName() << " constructed with no target (Basically unusable, but required)" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << this->getName() << " deconstructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade(), other.getTarget()) {
	std::cout << this->getName() << " copy constructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		std::cout	<< "ShrubberyCreationForm: No meaningful object properties can be copied. " << std::endl;
	}
	return *this;
}

// Other constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", SCF_SIGN_REQ, SCF_EXEQ_REQ, target) {
	std::cout << "Constructed " << this->getName() << " with target: " << target << std::endl;
}

// Public functions
void ShrubberyCreationForm::execute(Bureaucrat const &b) const {
	this->AForm::execute(b);

	std::ofstream file;
	std::string targetfile = this->getTarget() + "_shrubbery";

	file.open(targetfile);
	if(!file.is_open())
		throw std::ios_base::failure("Failed to open file " + targetfile + " for writing");

	file << "       _-_       "  << "       _-_       "  << std::endl;
	file << "    /~~   ~~\\    " << "    /~~   ~~\\    " << std::endl;
	file << " /~~         ~~\\ " << " /~~         ~~\\ " << std::endl;
	file << "{               }"  << "{               }"  << std::endl;
	file << " \\  _-     -_  / " << " \\  _-     -_  / " << std::endl;
	file << "   ~  \\ //  ~    " << "   ~  \\ //  ~    " << std::endl;
	file << "_- -   | | _- _  "  << "_- -   | | _- _  "  << std::endl;
	file << "  _ -  | |   -_  "  << "  _ -  | |   -_  "  << std::endl;
	file << "      // \\       " << "      // \\       " << std::endl;

	file.close();

	std::cout << "Generating ASCII tree file " << targetfile << std::endl;
}
