#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		ShrubberyCreationForm( void );

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &assign );
		virtual ~ShrubberyCreationForm( void );

		void createShrub( std::string target );
		void execute( Bureaucrat const &executor ) const;
};