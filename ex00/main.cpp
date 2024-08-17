#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "\n=== Test default constructor ===" << std::endl;
        Bureaucrat b1;
        std::cout << b1 << std::endl;

        std::cout << "\n=== Test parameterized constructor with valid grade ===" << std::endl;
        Bureaucrat b2("Alice", 100);
        std::cout << b2 << std::endl;

        std::cout << "\n=== Test parameterized constructor with grade too high ===" << std::endl;
        try {
            Bureaucrat b3("Bob", 0);
        } catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test parameterized constructor with grade too low ===" << std::endl;
        try {
            Bureaucrat b4("Charlie", 151);
        } catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test copy constructor ===" << std::endl;
        Bureaucrat b5(b2);
        std::cout << b5 << std::endl;

        std::cout << "\n=== Test assignment operator ===" << std::endl;
        Bureaucrat b6;
        b6 = b2;
        std::cout << b6 << std::endl;

        std::cout << "\n=== Test incrementGrade method ===" << std::endl;
        Bureaucrat b7("David", 2);
        std::cout << b7 << std::endl;
        b7.incrementGrade();
        std::cout << b7 << std::endl;
        try {
            b7.incrementGrade();
        } catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test decrementGrade method ===" << std::endl;
        Bureaucrat b8("Eve", 149);
        std::cout << b8 << std::endl;
        b8.decrementGrade();
        std::cout << b8 << std::endl;
        try {
            b8.decrementGrade();
        } catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}