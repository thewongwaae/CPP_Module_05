#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat lowLevel("LowLevel", 150);
	Bureaucrat midLevel("MidLevel", 75);
	Bureaucrat highLevel("HighLevel", 1);

	Intern intern;

	AForm *shrubberyForm = nullptr;
	AForm *robotomyForm = nullptr;
	AForm *pardonForm = nullptr;

	std::cout << "\n--- Intern Creating Forms ---\n";
	try {
		shrubberyForm = intern.makeForm("Shrubbery Creation Form", "Home");
		robotomyForm = intern.makeForm("Robotomy Request Form", "Bob");
		pardonForm = intern.makeForm("Presidential Pardon Form", "Alice");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	if (shrubberyForm && robotomyForm && pardonForm) {
		std::cout << "\n--- Signing Forms ---\n";
		try {
			lowLevel.signForm(*shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			midLevel.signForm(*robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			highLevel.signForm(*pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n--- Executing Forms ---\n";
		try {
			lowLevel.executeForm(*shrubberyForm); // Should fail due to low grade
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			midLevel.executeForm(*robotomyForm);  // Should fail due to low grade
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			highLevel.executeForm(*pardonForm);   // Should succeed
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "\n--- Destructs ---" << std::endl;

	delete shrubberyForm;
	delete robotomyForm;
	delete pardonForm;

	return 0;
}