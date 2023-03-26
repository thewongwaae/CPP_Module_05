#pragma once
#ifndef SHRUBBERYCREATIONFORM_CPP
#define SHRUBBERYCREATIONFORM_CPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form {
	private:
		const std::string _target;
		// moved this into private because pdf says only one constructor allowed
		ShrubberyCreationForm( void );
	
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &copy );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &assign );

		void execute( const Bureaucrat &executor ) const;

		std::string getTarget( void ) const;
};

std::ostream &operator<<( std::ostream &o, ShrubberyCreationForm *form );

#endif