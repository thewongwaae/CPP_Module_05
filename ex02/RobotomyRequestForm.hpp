#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		RobotomyRequestForm( void );

	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=( const RobotomyRequestForm &assign );
		~RobotomyRequestForm( void );

		void execute( Bureaucrat const &executor ) const;
};