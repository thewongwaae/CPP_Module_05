#include "Form.hpp"

Form::Form( void ) : _name("Mysterious form"), _signed(false), _gradeSign(150), _gradeExec(150) {
	std::cout	<< GREEN << "Form " << _name
				<< "with sign grade [" << _gradeSign << "] "
				<< " and sign exec grade [" << _gradeExec 
				<< "] constructed" << RESET << std::endl;
}

Form::Form( std::string name ) : _name(name), _signed(false), _gradeSign(150), _gradeExec(150) {
	std::cout	<< GREEN << "Form " << _name
				<< "with sign grade [" << _gradeSign << "] "
				<< " and sign exec grade [" << _gradeExec 
				<< "] constructed" << RESET << std::endl;
}

Form::Form( int gradeSign, int gradeExec ) : _name("Mysterious form"), _signed(false) {
	std::cout	<< GREEN << "Trying to create Form " << _name
				<< "with sign grade [" << gradeSign << "] "
				<< " and sign exec grade [" << gradeExec 
				<< "]" << RESET << std::endl;
	
	std::cout	<< GREEN << "Form " << _name
				<< "with sign grade [" << _gradeSign << "] "
				<< " and sign exec grade [" << _gradeExec 
				<< "] constructed" << RESET << std::endl;
}

Form::Form( std::string name, int gradeSign, int gradeExec ) : _name(name), _signed(false) {
	std::cout	<< GREEN << "Form " << _name
				<< "with sign grade [" << gradeSign << "] "
				<< " and sign exec grade [" << gradeExec 
				<< "] constructed" << RESET << std::endl;
}

Form::Form( const Form &copy ) {

}

Form::~Form( void ) {

}

Form &Form::operator=( const Form &assign ) {

}

void Form::setReq( int gradeSign, int gradeExec ) {
	if (gradeSign )
}

void Form::sign( Bureaucrat &name ) {

}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

std::ostream &operator<<( std::ostream &o, Form *b) {
	std::cout	<< "Form " << 
}
