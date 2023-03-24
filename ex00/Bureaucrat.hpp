#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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

	class GradeTooHighException : public std::exception {
		public:
			// some references declare and write function definition in the hpp this way
			//const char* what() noexcept override
			
			// but to define in cpp, declare this way
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			// what() is the error message printer for the exception class
			const char* what() const throw();
	};
};

std::ostream &operator<<( std::ostream &o, Bureaucrat *b );

#endif