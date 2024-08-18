#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "\n=== Test Form construction and grade validation ===" << std::endl;
        try {
            Form f1("Form1", 1, 1);
            std::cout << &f1 << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            Form f2("Form2", 0, 1);
            std::cout << &f2 << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            Form f3("Form3", 1, 151);
            std::cout << &f3 << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test Form signing ===" << std::endl;
        try {
            Bureaucrat b1("Frank", 50);
            Form f4("Form4", 100, 100);
            std::cout << &f4 << std::endl;
            b1.signForm(f4); // Should succeed
            std::cout << &f4 << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            Bureaucrat b2("Grace", 150);
            Form f5("Form5", 100, 100);
            std::cout << &f5 << std::endl;
            b2.signForm(f5); // Should throw exception
            std::cout << &f5 << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test Form copy constructor and assignment operator ===" << std::endl;
        try {
            Form f6("Form6", 50, 50);
            Form f7(f6); // Copy constructor
            std::cout << &f6 << std::endl;
            std::cout << &f7 << std::endl;

            Form f8("Form8", 100, 100);
            f8 = f6; // Assignment operator
            std::cout << &f8 << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}