#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) {

}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &assign ) {

}

Bureaucrat::~Bureaucrat( void ) {

}

std::string	Bureaucrat::getName( void ) {
	return (_name);
}

int Bureaucrat::getGrade( void ) {
	return (_grade);
}

void	Bureaucrat::promote( void ) {
	if (_grade == 150)
		
}

void	Bureaucrat::demote( void ) {

}