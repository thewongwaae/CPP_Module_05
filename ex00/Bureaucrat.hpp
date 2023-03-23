#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat &operator=( const Bureaucrat &assign );
		~Bureaucrat( void );

		std::string	getName( void );
		int			getGrade( void );
		void		promote( void );
		void		demote( void );
};

#endif