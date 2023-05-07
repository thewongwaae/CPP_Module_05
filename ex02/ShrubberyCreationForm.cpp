#include "ShrubberyCreationForm.hpp"

/* -------------------- Constructors, Operators, Deconstructors -------------------- */

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", 145, 137), _target("default"){
	std::cout << "ShrubberyCreationForm constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout	<< "ShrubberyCreationForm "
				<< _target << " constructed"
				<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) : Form("ShrubberyCreationForm", 145, 137), _target(copy.getTarget()){
	*this = copy;
	std::cout << "ShrubberyCreationForm copied" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign ) {
	if (this == &assign)
		return *this;

	return *this;
	std::cout << "ShrubberyCreationForm assigned" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "ShrubberyCreationForm destructed" << std::endl;
}

/* -------------------- Member Functions -------------------- */

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	if ((int)executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (Form::FormNotSignedException());
	else {
		std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());

		outfile << "     ccee88oo\n"
				<< "  C8O8O8Q8PoOb o8oo\n"
				<< " dOB69QO8PdUOpugoO9bD\n"
				<< "CgggbU8OU qOp qOdoUOdcb\n"
				<< "    6OuU  /p u gcoUodpP\n"
				<< "      \\\\\\//  /douUP\n"
				<< "        \\\\\\////\n"
				<< "         |||/\\n"
				<< "         |||\\/\n"
				<< "         |||||\n"
				<< "   .....//||||\\....\n"
				<< std::endl;

		outfile.close();
	}
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return this->_target;
}

std::ostream &operator<<( std::ostream &o, ShrubberyCreationForm *a ) {
	o	<< "Shrubbery Form " << a->getName()
		<< "\n\tSign grade: " << a->getGradeSign()
		<< "\n\tExec grade: " << a->getGradeExec()
		<< "\n\tSigned? " << a->getSigned()
		<< std::endl;
	return o;
}