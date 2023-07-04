#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat; // Forward declaration

class AForm {
	private:
		const std::string	name;
		bool				is_signed;
		const int			signGrade;
		const int			executeGrade;
		std::string			target;

		// Private functions
		void checkGrade();
	public:
		// OCCF
		AForm();
		virtual ~AForm() = 0;
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		// Other constructors
		AForm(std::string name, int signGrade = 150, int executeGrade = 150, std::string target = "");

		// Public functions
		std::string getName() const;
		std::string getPossessiveName() const;
		std::string getTarget() const;
		bool getSignatureStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat const& b);
		virtual void execute(Bureaucrat const& b) const;

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
				SignGradeTooLowException(Bureaucrat const& b, AForm const& f);
				virtual ~SignGradeTooLowException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
		class ExecuteGradeTooLowException : public GradeTooLowException {
			private:
				std::string message;
			public:
				ExecuteGradeTooLowException(Bureaucrat const& b, AForm const& f);
				virtual ~ExecuteGradeTooLowException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
		class AlreadySignedException : public std::exception {
			private:
				std::string message;
			public:
				AlreadySignedException(AForm const& f);
				virtual ~AlreadySignedException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
		class NotSignedException : public std::exception {
			private:
				std::string message;
			public:
				NotSignedException(AForm const& f);
				virtual ~NotSignedException() _NOEXCEPT;
				virtual const char* what() const _NOEXCEPT;
		};
};

// Friend functions
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif