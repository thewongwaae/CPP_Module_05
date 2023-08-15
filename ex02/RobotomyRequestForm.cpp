#include "RobotomyRequestForm.hpp"
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45) {
	_target	= "Unknown";
	std::cout << "Robotomy Request Form " + getName() + " constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45) {
	_target	= target;
	std::cout << "Robotomy Request Form " + getName() + " constructed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) : AForm( copy ) {
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &assign ) {
	this->_target = assign._target;
	return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	srand((unsigned) time(NULL));
	int robotomise_or_not = rand() % 2;

	std::cout << "Executor: " << executor.getName() << std::endl;
	std::cout << "Initiating Robotomy on target: " << _target << std::endl;
	std::cout << "BRRRRRRRR  BRRRRRRRRRR WHIRRRRRR BRBRBRBRBRBR" << RESET << std::endl;

	if (robotomise_or_not)
		std::cout << "Target " << _target << " robotomized successfully.";
	else
		std::cout << "Target " << _target << " robotomy failed.";
	std::cout << std::endl;
}