#include "RobotomyRequestForm.hpp"

/* -------------------- Constructors, Operators, Deconstructors -------------------- */

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout	<< "RobotomyRequestForm "
				<< _target << " constructed"
				<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) : Form("RobotomyRequestForm", 72, 45), _target(copy.getTarget()) {
	*this = copy;
	std::cout << "RobotomyRequestForm copied" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &assign ) {
if (this == &assign)
	return *this;

return *this;
	std::cout << "RobotomyRequestForm assigned" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "RobotomyRequestForm destructed" << std::endl;
}

/* -------------------- Member Functions -------------------- */

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	if ((int)executor.getGrade() > this->getGradeExec())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw(Form::FormNotSignedException());
	else if (rand() % 2 == 0)
		std::cout	<< "WHIRRRRRRR!! "
					<< this->getTarget() << " was robotomized"
					<< std::endl;
	else
		std::cout << "Robotmy failed..." << std::endl;
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm *a ) {
	o	<< "Shrubbery Form " << a->getName()
		<< "\n\tSign grade: " << a->getGradeSign()
		<< "\n\tExec grade: " << a->getGradeExec()
		<< "\n\tSigned? " << a->getSigned()
		<< std::endl;
	return o;
}