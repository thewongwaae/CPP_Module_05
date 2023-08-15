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
		virtual ~RobotomyRequestForm( void );

		void robotomize( std::string target );
		void execute( Bureaucrat const &executor ) const;
};