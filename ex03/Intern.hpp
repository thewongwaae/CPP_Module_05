#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
	private:
		AForm *shrubberyCreationForm( std::string target );
		AForm *robotomyRequestForm( std::string target );
		AForm *presidentialPardonForm( std::string target );

	public:
		Intern( void );
		Intern( Intern const &copy );
		Intern &operator=( Intern const &copy );
		~Intern( void );

		AForm *makeForm( std::string form, std::string target );

		class InvalidFormName : std::exception {
			public:
				virtual const char* what() const throw();
		};
};