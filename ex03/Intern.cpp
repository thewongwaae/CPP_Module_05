#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Intern constructed" << std::endl;
}

Intern::Intern( Intern const &copy ) {
	(void) copy;
}

Intern &Intern::operator=( Intern const &copy ) {
	if (this != &copy)
		*this = copy;
	return *this;
}

Intern::~Intern( void ) {
	std::cout << "Intern detructed" << std::endl;
}


AForm *Intern::shrubberyCreationForm( std::string target ) {
	AForm *ret = new ShrubberyCreationForm(target);
	std::cout << "Intern created Shrubbery Creation Form, targetting: " << target << "." << std::endl;
	return ret;
}

AForm *Intern::robotomyRequestForm( std::string target ) {
	AForm *ret = new RobotomyRequestForm(target);
	std::cout << "Intern created Robotomy Request Form, targetting: " << target << "." << std::endl;
	return ret;
}

AForm *Intern::presidentialPardonForm( std::string target ) {
	AForm *ret = new PresidentialPardonForm(target);
	std::cout << "Intern created Presidential Pardon Form, targetting: " << target << "." << std::endl;
	return ret;
}


AForm *Intern::makeForm( std::string form, std::string target ) {
	typedef AForm *(Intern::*formTypes)(std::string);

	formTypes forms[3] = {&Intern::shrubberyCreationForm, &Intern::robotomyRequestForm, &Intern::presidentialPardonForm};
	std::string formNames[] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	
	for (int i = 0; i < 3; i++) {
		if (form == formNames[i]) {
			return (this->*forms[i])(target);
		}
	}
	throw Intern::InvalidFormName();
}


const char* Intern::InvalidFormName::what() const throw() {
	return "Could not find the form you are looking for.";
}