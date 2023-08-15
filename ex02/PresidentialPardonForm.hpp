#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		PresidentialPardonForm( void );

	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=( const PresidentialPardonForm &assign );
		virtual ~PresidentialPardonForm( void );

		void pardon( std::string target );
		void execute( Bureaucrat const &executor ) const;
};