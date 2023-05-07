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

Form::Form( const Form &copy ) : _name(copy.getName() + "_copy"), _signed(copy.getSigned()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()) {
	std::cout	<< "Form " << copy.getName()
				<< " copied into " << this->getName()
				<< std::endl;
}

Form::~Form( void ) {
	std::cout	<< "Form " << _name << " destructed" << std::endl;
}

// can't override because most vars are const
Form &Form::operator=( const Form &assign ) {
	if (this == &assign)
		return *this;
	return *this;
}

void Form::beSigned( Bureaucrat &person ) {
	if (person.getGrade() > this->getGradeSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (!getSigned()) {
		_signed = true;
		std::cout << "Form " << _name << " was signed by " << person.getName() << std::endl;
	}
	else
		std::cout << "Form " << _name << " is already signed" << std::endl;
}

std::string Form::getName( void ) const {
	return _name;
}

int Form::getGradeSign( void ) const {
	return _gradeSign;
}

int Form::getGradeExec( void ) const {
	return _gradeExec;
}

bool Form::getSigned( void ) const {
	return _signed;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form's grade requirement too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form's grade requirement too low.");
}

const char *Form::FormNotSignedException::what() const throw() {
	return ("Unable to execute, Form has not been signed.");
}

std::ostream &operator<<( std::ostream &o, Form *f) {
	o	<< "Form " << f->getName()
		<< "\nSign req " << f->getGradeSign()
		<< "\nExec req " << f->getGradeExec()
		<< "\nSigned? " << f->getSigned()
		<< std::endl;
	return o;
}
