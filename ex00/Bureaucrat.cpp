#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("none") {
	this->_grade = LOWEST;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw  Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & obj ) {
	if (obj._grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (obj._grade > LOWEST)
		throw  Bureaucrat::GradeTooLowException();
	this->_grade = obj._grade;
	return *this;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & obj ) {
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	this->_grade--;
	if (this->_grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade > LOWEST)
		throw  Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()  {
	return "TooLowException";
}