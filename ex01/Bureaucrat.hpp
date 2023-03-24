#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

# define RESET "\033[0m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define YELLOW "\033[38;5;220m"
# define GREEN "\033[32m"
# define PURPLE "\033[38;5;129m"

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string name );
		Bureaucrat( int grade );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat &operator=( const Bureaucrat &assign );
		~Bureaucrat( void );

		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		setGrade( int grade );
		void		promote( void );
		void		demote( void );

		void		signForm( Form &f );

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<( std::ostream &o, Bureaucrat *b );

#endif