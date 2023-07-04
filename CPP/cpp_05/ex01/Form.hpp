#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const		std::string name;
		bool		is_signed;
		const int	signGrade;
		const int	executeGrade;

		// Private functions
		void checkGrade();
	public:
		// OCCF
		Form();
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		// Other constructors
		Form(std::string name, int signGrade = 150, int executeGrade = 150);

		// Public functions
		std::string getName() const;
		std::string getPossessiveName() const;
		bool getSignatureStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat& b);

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
		class SignGradeTooLowException : public GradeTooLowException {
			private:
				std::string message;
			public:
				SignGradeTooLowException(Bureaucrat& b, Form& f);
				virtual ~SignGradeTooLowException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
		class AlreadySignedException : public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		};
};

// Friend functions
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif