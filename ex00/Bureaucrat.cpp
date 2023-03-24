#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("lvl1 crook"), _grade(150) {
	std::cout	<< GREEN << "Bureaucrat " << _name
				<< " [" << _grade << "] constructed"
				<< RESET << std::endl;
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(150) {
	std::cout	<< GREEN << "Bureaucrat " << _name
				<< " [" << _grade << "] constructed"
				<< RESET << std::endl;
}

Bureaucrat::Bureaucrat( int grade ) : _name("lvl1 crook") {
	std::cout	<< YELLOW << "Trying to construct Bureaucrat " << _name
				<< " [" << _grade << std::endl;
	try
	{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr	<< RED << e.what() << '\n'
					
	}
	
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
	std::cout	<< "Bureaucrat " << _name
				<< " [" << _grade << "] constructed"
				<< std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) {
	*this = copy;
	std::cout	<< "Bureaucrat " << _name
				<< " [" << _grade << "] copied"
				<< std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &assign ) {
	if (this != &assign)
		_grade = assign.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout	<< "Bureaucrat " << _name << " deconstructed"
				<< std::endl;
}

std::string	Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::setGrade( int grade ) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

void	Bureaucrat::promote( void ) {
	if (_grade == 150)
		throw()
}

void	Bureaucrat::demote( void ) {

}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade too low");
}

std::ostream &operator<<( std::ostream &o, Bureaucrat *b ) {
	o	<< "Bureaucrat " << b->getName()
		<< " [" << b->getGrade() << "] constructed"
		<< std::endl;
}
