#include "AForm.hpp"

// OCCF
AForm::AForm() : name(""), signGrade(MIN_GRADE), executeGrade(MIN_GRADE) {
	this->is_signed = false;
	this->target = "";
	std::cout	<< "AForm " << this->getName()
				<< " constructed with default required grades (" << MIN_GRADE << ")"
				<< std::endl;
}

AForm::~AForm() {
	std::cout << "AForm " << this->getName() << " deconstructed" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), 
								signGrade(other.getSignGrade()),
								executeGrade(other.getExecuteGrade()),
								target(other.getTarget()) {
	this->is_signed = false;
	this->checkGrade();
	std::cout	<< "AForm " << this->getName()
				<< " constructed with signGrade(" << this->getSignGrade()
				<< ") and executeGrade(" << this->getExecuteGrade() << ")"
				<< std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		this->is_signed = other.getSignatureStatus();
		this->target = other.getTarget();
		std::cout	<< "Copying AForm " << other.getPossessiveName() << " signature status ("
					<< other.getSignatureStatus() << ")" << std::endl;
	}
	return *this;
}

// Other constructors
AForm::AForm(std::string name, int signGrade, int executeGrade, std::string target) 
													:name(name), 
													signGrade(signGrade), 
													executeGrade(executeGrade),
													target(target) {
	this->is_signed = false;
	this->checkGrade();
	std::cout	<< "Constructed AForm " << this->getName() 
				<< " with signGrade (" << this->getSignGrade()
				<< ") and executeGrade (" << this->getExecuteGrade() << ")" 
				<< std::endl;
}

// Public functions
std::string AForm::getName() const {
	return this->name;
}

std::string AForm::getPossessiveName() const {
	if (this->name.back() == 's' || this->name.back() == 'x')
		return this->name + '\'';
	else
		return this->name + "\'s";
}

std::string AForm::getTarget() const {
	return this->target;
}

bool AForm::getSignatureStatus() const {
	return this->is_signed;
}

int AForm::getSignGrade() const {
	return this->signGrade;
}

int AForm::getExecuteGrade() const {
	return this->executeGrade;
}

void AForm::beSigned(Bureaucrat const& b) {
	if (this->is_signed)
		throw AForm::NotSignedException(*this);
	if (b.getGrade() <= this->getSignGrade())
		this->is_signed = true;
	else
		throw AForm::SignGradeTooLowException(b, *this);
}

void AForm::execute(Bureaucrat const &b) const
{
	if(!this->is_signed)
		throw AForm::NotSignedException(*this); //#TODO make exception
	if(b.getGrade() > this->getExecuteGrade())
		throw AForm::ExecuteGradeTooLowException(b, *this);
}

// Exception classes
	// Exception constructors
	AForm::GradeTooHighException::GradeTooHighException(int givenGrade) {
		std::stringstream ss;
		ss	<< "AForm::GradeTooHighException: Grade cannot be higher than "
			<< MAX_GRADE << ". Grade given: " << givenGrade;
		this->message = ss.str();
	};

	AForm::GradeTooLowException::GradeTooLowException(int givenGrade) {
		std::stringstream ss;
		ss	<< "AForm::GradeTooLowException: Grade cannot be lower than "
			<< MIN_GRADE << ". Grade given: " << givenGrade;
		this->message = ss.str();
	};

	AForm::SignGradeTooLowException::SignGradeTooLowException(Bureaucrat const& b, AForm const& f) : GradeTooLowException(b.getGrade()) {
		std::stringstream ss;
		ss	<< "AForm::SignGradeTooLowException: " << b.getPossessiveName()
			<< " grade (" << b.getGrade() << ") is too low to sign " << f.getName()
			<< " (" << f.getSignGrade() << "+)";
		this->message = ss.str();
	}

	AForm::ExecuteGradeTooLowException::ExecuteGradeTooLowException(Bureaucrat const& b, AForm const& f) : GradeTooLowException(b.getGrade()) {
		std::stringstream ss;
		ss	<< "AForm::ExecuteGradeTooLowException: " << b.getPossessiveName()
			<< " grade (" << b.getGrade() << ") is too low to execute " << f.getName()
			<< " (" << f.getSignGrade() << "+)";
		this->message = ss.str();
	}

	AForm::AlreadySignedException::AlreadySignedException(AForm const& f) {
		std::stringstream ss;
		ss	<< "AForm::AlreadySignedException: " << f.getName() 
			<< " was signed already";
		this->message = ss.str();
	}

	AForm::NotSignedException::NotSignedException(AForm const& f) {
		std::stringstream ss;
		ss	<< "AForm::NotSignedException: Cannot execute " << f.getName() << " because it has not been signed by a bureaucrat with a sufficient grade";
		this->message = ss.str();
	}

	// Exception Destructors
	AForm::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
	AForm::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
	AForm::SignGradeTooLowException::~SignGradeTooLowException() _NOEXCEPT {}
	AForm::ExecuteGradeTooLowException::~ExecuteGradeTooLowException() _NOEXCEPT {}
	AForm::AlreadySignedException::~AlreadySignedException() _NOEXCEPT {}
	AForm::NotSignedException::~NotSignedException() _NOEXCEPT {}

	// Exception Public functions
	const char* AForm::GradeTooHighException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* AForm::GradeTooLowException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* AForm::SignGradeTooLowException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* AForm::ExecuteGradeTooLowException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* AForm::AlreadySignedException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

	const char* AForm::NotSignedException::what() const _NOEXCEPT {
		return this->message.c_str();
	}

// Friend functions
std::ostream& operator<<(std::ostream& os, const AForm& f) {
	std::string signstatus = f.getSignatureStatus() ? "signed" : "not signed";

	return os	<< "AForm " << f.getName() 
				<< " with signGrade (" << f.getSignGrade() 
				<< ") and executeGrade (" << f.getExecuteGrade()
				<< ") and target " << f.getTarget()
				<< " is " << signstatus;
}

// Private functions
void AForm::checkGrade()
{
	if (this->signGrade > MIN_GRADE)
		throw AForm::GradeTooLowException(this->signGrade);
	if (this->signGrade <= MAX_GRADE)
		throw AForm::GradeTooHighException(this->signGrade);
	if (this->executeGrade > MIN_GRADE)
		throw AForm::GradeTooLowException(this->executeGrade);
	if (this->executeGrade <= MAX_GRADE)
		throw AForm::GradeTooHighException(this->executeGrade);
}
