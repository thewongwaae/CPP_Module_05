#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(150) {
	std::cout << "Bureaucrat " + _name + " constructed." << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;

	std::cout << "Bureaucrat " + _name + " constructed." << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &copy ) {
	this->_grade = copy._grade;
	return *this;
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) : _name(copy._name) {
	*this = copy;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " + _name + " destructed." << std::endl;
}


std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}


void Bureaucrat::incrementGrade() {
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade > 150)
		throw  Bureaucrat::GradeTooLowException();
}


const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()  {
	return "TooLowException";
}


std::ostream &operator<<( std::ostream & o, Bureaucrat const & obj ) {
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}