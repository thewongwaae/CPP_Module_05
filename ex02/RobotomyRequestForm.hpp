#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include <iostream>

class RobotomyRequestForm {
	private:

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &copy );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &assign );
		~RobotomyRequestForm( void );
};

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm *a );

#endif