#pragma once
#include <string>
#include <iostream>

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat  {
	private:
		std::string const	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & obj);

		std::string getName() const;
		int         getGrade() const;

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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj);