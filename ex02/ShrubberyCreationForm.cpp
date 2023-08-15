#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137) {
	_target	= "Unknown";
	std::cout << "Shrubbery Creation Form " + getName() + " constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137) {
	_target	= target;
	std::cout << "Shrubbery Creation Form " + getName() + " constructed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) : AForm( copy ) {
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign ) {
	this->_target = assign._target;
	return *this; 
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {

	std::cout << "Executor: " << executor.getName() << std::endl;
	std::cout << "Shrubbery Created!" << std::endl;
	std::ofstream file(_target + "_shrubbery");
	file << "//          &&& &&  & &&" << std::endl;
	file << "//      && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "//      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "//   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	file << "//  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "//&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << "// ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "//     &&     \\|||" << std::endl;
	file << "//             |||" << std::endl;
	file << "//             |||" << std::endl;
	file << "//             |||" << std::endl;
	file << "//       , -=-~  .-^- _" << std::endl;
	file.close();
}