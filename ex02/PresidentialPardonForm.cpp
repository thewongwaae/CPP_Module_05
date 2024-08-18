#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5) {
	_target	= "Unknown";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5) {
	_target	= target;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy ) : AForm( copy ) {
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &assign ) {
	this->_target = assign._target;
	return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	std::cout << "Executor " << executor.getName() << " initiated pardon." << std::endl;
	std::cout << _target << " has been pardoned by President Zaphod Beeblebrox." << std::endl;
}