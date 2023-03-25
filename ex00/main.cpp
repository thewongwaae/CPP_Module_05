#include "Bureaucrat.hpp"

int main( void ) {
	std::cout << "[ TESTING CONSTRUCTS ]" << std::endl;
	Bureaucrat();
	Bureaucrat("Bob");
	Bureaucrat(150);
	Bureaucrat("Cat", 130);

	std::cout << "[ TESTING WRONG VALUE CONSTRUCTS ]" << std::endl;
	Bureaucrat(160);
	Bureaucrat("Poggies", 0);

	std::cout << "[ PROMOTE AND DEMOTE ]" << std::endl;
	Bureaucrat *bob = new Bureaucrat();
	std::cout << bob;
	bob->promote();
	std::cout << bob;

	delete bob;

	system("leaks Bureaucrats");
	return (0);
}
