#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm; // Forward declaration

class Bureaucrat {
	private:
		const	std::string name;
		int		grade;
		
		// Private functions
		void	checkGrade(int grade);
	public:
		//OCCF:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		// Other constructors
		Bureaucrat(std::string name, int grade);

		// Public functions;
		const std::string getName() const;
		std::string getPossessiveName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& f);
		void executeForm(AForm const& f);

		// Exception classes
		class GradeTooHighException : public std::exception {
			private: 
				std::string message;
			public:
				GradeTooHighException(int givenGrade);
				virtual ~GradeTooHighException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception {
			private: 
				std::string message;
			public:
				GradeTooLowException(int givenGrade);
				virtual ~GradeTooLowException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
};

// Friend functions
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif