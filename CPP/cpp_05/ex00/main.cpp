#include "Bureaucrat.hpp"

int main()
{
	std::cout << "CREATING BUREAUCRATS" << std::endl;
	Bureaucrat a("Atron",  150);
	Bureaucrat b("Brutix", 1);
	Bureaucrat c("Caracal", 42);
	Bureaucrat d("Dramiel", 41);
	Bureaucrat e("Exequror", 7);
	Bureaucrat f("Ferox", 123);

	std::cout << std::endl << "PRINTING BUREAUCRATS" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl << "COPYING BUREAUCRATS" << std::endl;
	e = Bureaucrat(a);
	f = b;

	std::cout << std::endl << "PRINTING BUREAUCRATS" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl << "CAUSING EXCEPTIONS" << std::endl;
	try {
		a.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		while(1)
			c.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat g("Gila", -1);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat h("Hurricane", 300);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "PRINTING BUREAUCRATS" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl << "TEST FUNCTIONS" << std::endl;
	a.incrementGrade(); a.incrementGrade();
	b.decrementGrade(); b.decrementGrade();
	c.incrementGrade(); c.incrementGrade();

	std::cout << std::endl << "PRINTING TEST BUREAUCRATS" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << std::endl << "END OF MAIN" << std::endl;
}
