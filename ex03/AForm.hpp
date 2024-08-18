#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		AForm( void );
		AForm( std::string name );
		AForm( int gradeSign, int gradeExec );
		AForm( std::string name, int gradeSign, int gradeExec );
		AForm( const AForm &copy );
		AForm &operator=( const AForm &assign );
		virtual ~AForm( void );

		void beSigned( const Bureaucrat &person );
		virtual void execute( const Bureaucrat &executor ) const = 0;

		std::string getName( void ) const;
		int getGradeSign( void ) const;
		int getGradeExec( void ) const;
		bool getSigned( void ) const;
		

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &o, AForm *f );