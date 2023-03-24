#include "Form.hpp"

Form::Form( void ) : _name("Mysterious form"), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form( std::string name ) : _name(name), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form( int gradeSign, int gradeExec ) : _name("Mysterious form"), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {

}

Form::Form( std::string name, int gradeSign, int gradeExec ) : _name(name), _signed(false), _gradeSign(150), _gradeExec(150) {

}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
