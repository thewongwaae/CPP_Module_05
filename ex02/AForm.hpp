#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		virtual void execute( Bureaucrat const &executor ) const = 0;

		AForm( void );
		AForm( std::string name );
		AForm( int gradeSign, int gradeExec );
		AForm( std::string name, int gradeSign, int gradeExec );
		AForm( const AForm &copy );
		~AForm( void );
		AForm &operator=( const AForm &assign );

		void beSigned( Bureaucrat &person );

		std::string getName( void ) const;
		int getGradeSign( void ) const;
		int getGradeExec( void ) const;
		bool getSigned( void ) const;
		

	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
	
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};

	class FormSigned : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &o, AForm *b );