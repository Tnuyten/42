#include "Form.hpp"

// OCCF
Form::Form() : name(""), signGrade(MIN_GRADE), executeGrade(MIN_GRADE) {
	this->is_signed = false;
	std::cout	<< "Form " << this->getName()
				<< " constructed with default required grades (" << MIN_GRADE << ")"
				<< std::endl;
}

Form::~Form() {
	std::cout << "Form " << this->getName() << " deconstructed" << std::endl;
}

Form::Form(const Form& other) : name(other.name), 
								signGrade(other.getSignGrade()),
								executeGrade(other.getExecuteGrade()) {
	this->is_signed = false;
	this->checkGrade();
	std::cout	<< "Form " << this->getName()
				<< " constructed with signGrade(" << this->getSignGrade()
				<< ") and executeGrade(" << this->getExecuteGrade() << ")"
				<< std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		this->is_signed = other.getSignatureStatus();
		std::cout	<< "Copying Form " << other.getPossessiveName() << " signature status ("
					<< other.getSignatureStatus() << ")" << std::endl;
	}
	return *this;
}

// Other constructors
Form::Form(std::string name, int signGrade, int executeGrade) :name(name), 
																	signGrade(signGrade), 
																	executeGrade(executeGrade) {
	this->is_signed = false;
	this->checkGrade();
	std::cout	<< "Constructed Form " << this->getName() 
				<< " with signGrade (" << this->getSignGrade()
				<< ") and executeGrade (" << this->getExecuteGrade() << ")" 
				<< std::endl;
}

// Public functions
std::string Form::getName() const {
	return this->name;
}

std::string Form::getPossessiveName() const {
	if (this->name.back() == 's' || this->name.back() == 'x')
		return this->name + '\'';
	else
		return this->name + "\'s";
}

bool Form::getSignatureStatus() const {
	return this->is_signed;
}

int Form::getSignGrade() const {
	return this->signGrade;
}
int Form::getExecuteGrade() const {
	return this->executeGrade;
}
void Form::beSigned(Bureaucrat& b) {
	if (this->is_signed)
		throw Form::AlreadySignedException();
	if (b.getGrade() <= this->getSignGrade())
		this->is_signed = true;
	else
		throw Form::SignGradeTooLowException(b, *this);
}

// Exception classes

	// Exception constructors
	Form::GradeTooHighException::GradeTooHighException(int givenGrade) {
		std::stringstream ss;
		ss	<< "Form::GradeTooHighException: Grade cannot be higher than "
			<< MAX_GRADE << ". Grade given: " << givenGrade;
		this->message = ss.str();
	};

	Form::GradeTooLowException::GradeTooLowException(int givenGrade) {
		std::stringstream ss;
		ss	<< "Form::GradeTooLowException: Grade cannot be lower than "
			<< MIN_GRADE << ". Grade given: " << givenGrade;
		this->message = ss.str();
	};

	Form::SignGradeTooLowException::SignGradeTooLowException(Bureaucrat& b, Form& f) : GradeTooLowException(b.getGrade()) {
		std::stringstream ss;
		ss	<< "Form::SignGradeTooLowException: " << b.getPossessiveName()
			<< " grade (" << b.getGrade() << ") is too low to sign " << f.getName()
			<< " (" << f.getSignGrade() << "+)";
		this->message = ss.str();
	}

	// Exception Destructors
	Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
	Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
	Form::SignGradeTooLowException::~SignGradeTooLowException() _NOEXCEPT {}

	// Exception Public functions
	const char* Form::GradeTooHighException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* Form::GradeTooLowException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* Form::AlreadySignedException::what() const _NOEXCEPT {
		return "Form::AlreadySignedException: Form was signed already";
	}

	const char* Form::SignGradeTooLowException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

// Friend functions
std::ostream& operator<<(std::ostream& os, const Form& f) {
	std::string signstatus = f.getSignatureStatus() ? "signed" : "not signed";

	return os	<< "Form " << f.getName() 
				<< " with signGrade (" << f.getSignGrade() 
				<< ") and executeGrade (" << f.getExecuteGrade()
				<< ") is " << signstatus;
}

// Private functions
void Form::checkGrade()
{
	if (this->signGrade > MIN_GRADE)
		throw Form::GradeTooLowException(this->signGrade);
	if (this->signGrade <= MAX_GRADE)
		throw Form::GradeTooHighException(this->signGrade);
	if (this->executeGrade > MIN_GRADE)
		throw Form::GradeTooLowException(this->executeGrade);
	if (this->executeGrade <= MAX_GRADE)
		throw Form::GradeTooHighException(this->executeGrade);
}
