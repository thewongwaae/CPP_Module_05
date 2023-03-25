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
				<< " [" << grade << "]" << std::endl;
	try
	{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr	<< RED << e.what()
					<< " Setting grade to 1"
					<< std::endl;
		_grade = 1;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr	<< RED << e.what()
					<< " Setting grade to 150"
					<< std::endl;
		_grade = 150;
	}
	std::cout	<< GREEN << "Bureaucrat " << _name
				<< " [" << _grade << "] constructed"
				<< RESET << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	std::cout	<< YELLOW << "Trying to construct Bureaucrat " << _name
				<< " [" << grade << "]" << std::endl;
	try
	{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr	<< RED << e.what()
					<< " Setting grade to 1"
					<< std::endl;
		_grade = 1;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr	<< RED << e.what()
					<< " Setting grade to 150"
					<< std::endl;
		_grade = 150;
	}
	std::cout	<< GREEN << "Bureaucrat " << _name
				<< " [" << _grade << "] constructed"
				<< RESET << std::endl;
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
	bool fail = false;
	try
	{
		setGrade(_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		fail = true;
		std::cerr	<< RED << e.what()
					<< " Setting grade to 1"
					<< RESET << std::endl;
		_grade = 1;
	}
	if (!fail)
		std::cout << "Bureaucrat " << _name << " promoted to " << _grade <<  std::endl;
}

void	Bureaucrat::demote( void ) {
	bool fail = false;
	try
	{
		setGrade(_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		fail = true;
		std::cerr	<< RED << e.what()
					<< " Setting grade to 150"
					<< RESET << std::endl;
		_grade = 150;
	}
	if (!fail)
		std::cout << "Bureaucrat " << _name << " demoted to " << _grade <<  std::endl;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade too low.");
}

std::ostream &operator<<( std::ostream &o, Bureaucrat *b ) {
	o	<< "Bureaucrat " << b->getName()
		<< " [" << b->getGrade() << "]"
		<< std::endl;
	return o;
}
