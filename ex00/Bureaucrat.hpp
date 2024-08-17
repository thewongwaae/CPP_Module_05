#pragma once

#include <iostream>

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

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & obj );