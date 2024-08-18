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
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm( AForm &form ) const {
	form.beSigned(*this);
}

void Bureaucrat::executeForm( AForm const &form ) const {
	if (!form.getSigned())
		std::cout << form.getName() << " not signed" << std::endl;
	else if (form.getGradeExec() < this->getGrade())
		throw Bureaucrat::ExecGradeTooLowException();
	else {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
}


const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()  {
	return "Grade too low.";
}

const char * Bureaucrat::SignGradeTooLowException::what() const throw()  {
	return "Sign grade too low.";
}

const char * Bureaucrat::ExecGradeTooLowException::what() const throw()  {
	return "Exec grade too low.";
}


std::ostream &operator<<( std::ostream & o, Bureaucrat const & obj ) {
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}