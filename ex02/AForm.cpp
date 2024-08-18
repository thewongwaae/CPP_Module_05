#include "AForm.hpp"

AForm::AForm( void ) : _name("Mysterious Aform"), _signed(false), _gradeSign(150), _gradeExec(150) {
	std::cout	<< "AForm " << _name
				<< " with sign grade [" << _gradeSign << "] "
				<< "and sign exec grade [" << _gradeExec 
				<< "] constructed" << std::endl;
}

AForm::AForm( std::string name ) : _name(name), _signed(false), _gradeSign(150), _gradeExec(150) {
	std::cout	<< "AForm " << _name
				<< " with sign grade [" << _gradeSign << "] "
				<< "and sign exec grade [" << _gradeExec 
				<< "] constructed" << std::endl;
}

AForm::AForm( int gradeSign, int gradeExec ) : _name("Mysterious Aform"), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1)
		throw(GradeTooHighException());
	else if (gradeSign > 150 || gradeExec > 150)
		throw(GradeTooLowException());
	else {
		std::cout	<< "AForm " << _name
					<< " with sign grade [" << _gradeSign << "] "
					<< "and sign exec grade [" << _gradeExec 
					<< "] constructed" << std::endl;
	}
}

AForm::AForm( std::string name, int gradeSign, int gradeExec ) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1)
		throw(GradeTooHighException());
	else if (gradeSign > 150 || gradeExec > 150)
		throw(GradeTooLowException());
	else {
		std::cout	<< "AForm " << _name
					<< " with sign grade [" << _gradeSign << "] "
					<< "and sign exec grade [" << _gradeExec 
					<< "] constructed" << std::endl;
	}
}

AForm::AForm( const AForm &copy ) : _name(copy.getName() + "_copy"), _signed(copy.getSigned()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()) {
	std::cout	<< "AForm " << copy.getName()
				<< " copied into " << this->getName()
				<< std::endl;
}

AForm::~AForm( void ) {
	std::cout	<< "AForm " << _name << " destructed" << std::endl;
}

// can't override because most vars are const
AForm &AForm::operator=( const AForm &assign ) {
	if (this == &assign)
		return *this;
	return *this;
}


void AForm::beSigned( const Bureaucrat &person ) {
	if (person.getGrade() > this->getGradeSign()) {
		throw Bureaucrat::SignGradeTooLowException();
	}
	else if (!getSigned()) {
		_signed = true;
		std::cout << "Form " << _name << " was signed by " << person.getName() << std::endl;
	}
	else
		std::cout << "Form " << _name << " is already signed" << std::endl;
}


std::string AForm::getName( void ) const {
	return _name;
}

int AForm::getGradeSign( void ) const {
	return _gradeSign;
}

int AForm::getGradeExec( void ) const {
	return _gradeExec;
}

bool AForm::getSigned( void ) const {
	return _signed;
}


const char *AForm::GradeTooHighException::what() const throw() {
	return ("AForm's grade requirement too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("AForm's grade requirement too low.");
}

std::ostream &operator<<( std::ostream &o, AForm *f ) {
	o	<< "AForm " << f->getName()
		<< "\nSign req " << f->getGradeSign()
		<< "\nExec req " << f->getGradeExec()
		<< "\nSigned? " << f->getSigned()
		<< std::endl;
	return o;
}
