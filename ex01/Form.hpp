#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		Form( void );
		Form( std::string name );
		Form( int gradeSign, int gradeExec );
		Form( std::string name, int gradeSign, int gradeExec );
		Form( const Form &copy );
		~Form( void );
		Form &operator=( const Form &assign );

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
};

std::ostream &operator<<( std::ostream &o, Form *b );

#endif