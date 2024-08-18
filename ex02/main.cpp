#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat lowLevel("LowLevel", 150);
	Bureaucrat midLevel("MidLevel", 75);
	Bureaucrat highLevel("HighLevel", 1);

	ShrubberyCreationForm shrubberyForm("Home");
	RobotomyRequestForm robotomyForm("Bob");
	PresidentialPardonForm pardonForm("Alice");

	std::cout << "\n--- Signing Forms ---\n";
    try {
        lowLevel.signForm(shrubberyForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        midLevel.signForm(robotomyForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        highLevel.signForm(pardonForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n--- Executing Forms ---\n";
    try {
        lowLevel.executeForm(shrubberyForm); // Should fail due to low grade
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        midLevel.executeForm(robotomyForm);  // Should fail due to low grade
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        highLevel.executeForm(pardonForm);   // Should succeed
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n--- Destructs ---" << std::endl;

    return 0;
}