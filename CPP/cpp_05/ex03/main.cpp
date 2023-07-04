#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "CREATING BUREAUCRATS" << std::endl;
	Bureaucrat atron("Atron",  1);
	Bureaucrat brutix("Brutix", 15);
	Bureaucrat caracal("Caracal", 35);
	Bureaucrat dramiel("Dramiel", 55);
	Bureaucrat exequeror("Exequeror", 75);
	Bureaucrat ferox("Ferox", 140);
	Bureaucrat gila("Gila", 150);

	std::cout << std::endl << "CREATING FORM CREATOR" << std::endl;
	Intern noob;

	std::cout << std::endl << "CREATING FORMS" << std::endl;
	AForm *shrub = noob.makeForm("ShrubberyCreationForm", "woodland");				std::cout << std::endl;
	AForm *robo = noob.makeForm("RobotomyRequestForm", "AwesomeO 3000");			std::cout << std::endl;
	AForm *pardon = noob.makeForm("PresidentialPardonForm", "Thanksgiving Turkey");	std::cout << std::endl;
	AForm *notsigned = noob.makeForm("ShrubberyCreationForm", "unsigned");
	if(shrub == NULL || robo == NULL || pardon == NULL || notsigned == NULL)
		return (1);

	std::cout << std::endl << "SIGNING FORMS" << std::endl;
	ferox.signForm(*shrub);
	dramiel.signForm(*robo);
	brutix.signForm(*pardon);

	std::cout << std::endl << "PRINTING FORMS" << std::endl;
	std::cout << *shrub << std::endl;
	std::cout << *robo << std::endl;
	std::cout << *pardon << std::endl;
	std::cout << *notsigned << std::endl;

	std::cout << std::endl << "CAUSING EXCEPTIONS" << std::endl;
	try {
		AForm *failed = noob.makeForm("ThisFormDoesNotExist", "target");
		atron.executeForm(*failed);
	}
	catch (Intern::FormDoesNotExistException& e) {
		std::cerr << "makeForm Exception caught: " << e.what() << std::endl;
	}
	try {
		gila.executeForm(*shrub);
	}
	catch (AForm::GradeTooLowException& e) {
		std::cerr << "Execute exception caught: " << e.what() << std::endl;
	}
	try {
		atron.executeForm(*notsigned);
	}
	catch (AForm::NotSignedException& e) {
		std::cerr << "Execute exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << "EXECUTING FORMS" << std::endl;
	exequeror.executeForm(*shrub);
	std::cout << std::endl;
	caracal.executeForm(*robo);
	std::cout << std::endl;
	atron.executeForm(*pardon);

	std::cout << std::endl << "PRINTING BUREAUCRATS" << std::endl;
	std::cout << atron << std::endl;
	std::cout << brutix << std::endl;
	std::cout << caracal << std::endl;
	std::cout << dramiel << std::endl;
	std::cout << exequeror << std::endl;
	std::cout << ferox << std::endl;
	std::cout << gila << std::endl;
	
	std::cout << std::endl << "PRINTING FORMS" << std::endl;
	std::cout << *shrub << std::endl;
	std::cout << *robo << std::endl;
	std::cout << *pardon << std::endl;
	std::cout << *notsigned << std::endl;

	std::cout << std::endl << "DELETING OBJECTS" << std::endl;
	delete shrub;
	delete robo;
	delete pardon;
	delete notsigned;

	std::cout << std::endl << "END OF MAIN" << std::endl;
}