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

Form::Form( int gradeSign, int gradeExec ) : _name("Mysterious form"), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	std::cout	<< GREEN << "Trying to create Form " << _name
				<< "with sign grade [" << gradeSign << "] "
				<< " and sign exec grade [" << gradeExec 
				<< "]" << RESET << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw(GradeTooHighException());
	else if (gradeSign > 150 || gradeExec > 150)
		throw(GradeTooLowException());
	else {
		std::cout	<< GREEN << "Form " << _name
					<< "with sign grade [" << _gradeSign << "] "
					<< " and sign exec grade [" << _gradeExec 
					<< "] constructed" << RESET << std::endl;
	}
}

Form::Form( std::string name, int gradeSign, int gradeExec ) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	std::cout	<< GREEN << "Form " << _name
				<< "with sign grade [" << gradeSign << "] "
				<< " and sign exec grade [" << gradeExec 
				<< "] constructed" << RESET << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw(GradeTooHighException());
	else if (gradeSign > 150 || gradeExec > 150)
		throw(GradeTooLowException());
	else {
		std::cout	<< GREEN << "Form " << _name
					<< "with sign grade [" << _gradeSign << "] "
					<< " and sign exec grade [" << _gradeExec 
					<< "] constructed" << RESET << std::endl;
	}
}

Form::Form( const Form &copy ) {
	if (this != &copy)
		*this = copy;
}

Form::~Form( void ) {

}

Form &Form::operator=( const Form &assign ) {

}

void Form::beSigned( Bureaucrat &person ) {

}

std::string Form::getName( void ) {
	return _name;
}

int Form::getGradeSign( void ) {
	return _gradeSign;
}

int Form::getGradeExec( void ) {
	return _gradeExec;
}

bool Form::getSigned( void ) {
	return _signed;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

std::ostream &operator<<( std::ostream &o, Form *f) {
	o	<< "Form " << f->getName()
		<< "\nSign req " << f->getGradeSign()
		<< "\nExec req " << f->getGradeExec()
		<< "\nSigned? " << f->getSigned()
		<< std::endl;
	return o;
}
