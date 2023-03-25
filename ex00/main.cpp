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
}
