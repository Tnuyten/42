#include "Bureaucrat.hpp"

// OCCF
Bureaucrat::Bureaucrat() : name("") {
	this->grade = MIN_GRADE;
	std::cout << "Bureaucrat constructed (default)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
	this->checkGrade(other.grade);
	this->grade = other.grade;
	std::cout	<< "Bureaucrat " << this->name << " copy constructed with grade ("
				<< this->getGrade() << ")" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->getName() << " deconstructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
	{
		this->checkGrade(other.grade);
		this->grade = other.grade;
	}
	std::cout << "Copying Bureaucrat " << this->getPossessiveName() << " grade (" << this->getGrade() << ") from " << other.getName() << " with operator=" << std::endl;
	return *this;
}

// Other constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	this->checkGrade(grade);
	this->grade = grade;
	std::cout	<< "Bureaucrat " << this->name << " constructed with grade ("
				<< this->getGrade() << ")" << std::endl;
}

// Public functions
const std::string Bureaucrat::getName() const {
	return this->name;
}

std::string Bureaucrat::getPossessiveName() const {
	if (this->name.back() == 's' || this->name.back() == 'x')
		return this->name + '\'';
	else
		return this->name + "\'s";
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	this->checkGrade(this->grade - 1);
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	this->checkGrade(this->grade + 1);
	this->grade++;
}

// Exception classes

	// Exception Constructors
	Bureaucrat::GradeTooHighException::GradeTooHighException(int givenGrade) {
		std::stringstream ss;
		ss	<< "Bureaucrat::GradeTooHighException: Grade cannot be higher than "
			<< MAX_GRADE << ". Grade given: " << givenGrade;
		this->message = ss.str();
	};

	Bureaucrat::GradeTooLowException::GradeTooLowException(int givenGrade) {
		std::stringstream ss;
		ss	<< "Bureaucrat::GradeTooLowException: Grade cannot be lower than "
			<< MIN_GRADE << ". Grade given: " << givenGrade;
		this->message = ss.str();
	};

	// Exception Destructors
	Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
	Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}

	// Exception public functions
	const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

// Friend functions
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	return os << "Bureaucrat " << b.getName() << " with grade (" << b.getGrade() << ")";
}

// Private functions
void Bureaucrat::checkGrade(int grade)
{
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException(grade);
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException(grade);
}