#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
		
		Form( void );
		Form( std::string name );
		Form( int gradeSign, int gradeExec );
		Form( std::string name, int gradeSign, int gradeExec );

	public:
		Form( const Form &copy );
		virtual ~Form( void );
		Form &operator=( const Form &assign );

		void beSigned( Bureaucrat &person );

		virtual std::string getName( void ) const = 0;
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

	class FormNotSignedException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &o, Form *b );

#endif