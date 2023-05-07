#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public Form {
	private:
		const std::string _target;
		RobotomyRequestForm( void );
	
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &copy );
		~RobotomyRequestForm( void );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &assign );

		void execute( const Bureaucrat &executor ) const;

		std::string getTarget( void ) const;
};

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm *a );

#endif