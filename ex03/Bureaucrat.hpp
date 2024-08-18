#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat  {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat( std::string _name, int _grade );
		Bureaucrat( Bureaucrat const &copy );
		Bureaucrat &operator=( Bureaucrat const &copy );
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm( AForm &form ) const;
		void executeForm( AForm const &form ) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class SignGradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class ExecGradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & obj );