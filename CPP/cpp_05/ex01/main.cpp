#include "Bureaucrat.hpp"

int main()
{
	std::cout << "CREATING BUREAUCRATS" << std::endl;
	Bureaucrat a("Atron",  1);
	Bureaucrat b("Brutix", 130);
	Bureaucrat c("Caracal", 140);

	std::cout << std::endl << "CREATING FORMS" << std::endl;
	Form f1("AtronForm", 10, 10);
	Form f2("BrutixForm", 140, 140);
	Form f3("CaracalForm", 140);

	std::cout << std::endl << "PRINTING BUREAUCRATS" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl << "PRINTING FORMS" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	std::cout << std::endl << "CAUSING EXCEPTIONS" << std::endl;
	try {
		b.signForm(f1); // Brutix' grade is too low to sign this form.
	}
	catch (Form::GradeTooLowException& e) {	
		std::cerr << e.what() << std::endl;
	}

	try {
		b.signForm(f1); // Brutix' grade is too low to sign this form.
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "SIGNING FORMS" << std::endl;
	a.signForm(f1);
	b.signForm(f2);

	std::cout << std::endl << "MORE EXCEPTIONS" << std::endl;

	try {
		c.signForm(f2);
	}
	catch (Form::AlreadySignedException& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "PRINTING FORMS" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	std::cout << std::endl << "END OF MAIN" << std::endl;
}

