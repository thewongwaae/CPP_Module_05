#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public Form {
	private:
		const std::string _target;
		PresidentialPardonForm( void );
	
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &copy );
		~PresidentialPardonForm( void );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &assign );

		void execute( const Bureaucrat &executor ) const;

		std::string getTarget( void ) const;
};

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm *a );

#endif