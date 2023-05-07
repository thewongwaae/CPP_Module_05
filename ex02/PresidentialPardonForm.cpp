#include "PresidentialPardonForm.hpp"

/* -------------------- Constructors, Operators, Deconstructors -------------------- */

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("RobotomyRequestForm", 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("RobotomyRequestForm", 25, 5), _target(target) {
	std::cout	<< "PresidentialPardonForm "
				<< _target << " constructed"
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy ) : Form("RobotomyRequestForm", 25, 5), _target(copy.getTarget()) {
	*this = copy;
	std::cout << "PresidentialPardonForm copied" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &assign ) {
if (this == &assign)
	return *this;

return *this;
	std::cout << "PresidentialPardonForm assigned" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "PresidentialPardonForm destructed" << std::endl;
}

/* -------------------- Member Functions -------------------- */

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	if ((int)executor.getGrade() > this->getGradeExec())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw(Form::FormNotSignedException());
	else
		std::cout	<< this->getTarget()
					<< " has been pardoned by Zaphod Beeblebrox"
					<< std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm *a ) {
	o	<< "Shrubbery Form " << a->getName()
		<< "\n\tSign grade: " << a->getGradeSign()
		<< "\n\tExec grade: " << a->getGradeExec()
		<< "\n\tSigned? " << a->getSigned()
		<< std::endl;
	return o;
}