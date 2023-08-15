#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	// I hate making test files
	std::cout << "\033[35;1m\n[ GENERAL FORM TESTS ]\033[0m" << std::endl;

	std::string target = "DECOY";
	ShrubberyCreationForm *SCF = new ShrubberyCreationForm(target); //s145 e137
	RobotomyRequestForm *RRF = new RobotomyRequestForm(target); //s72 e45
	PresidentialPardonForm *PPF = new PresidentialPardonForm(target); //s25 e5
	std::cout << std::endl;

	std::cout << SCF;
	std::cout << RRF;
	std::cout << PPF;

	std::cout << "\033[35;1m\n[ INSTANTIATING BUREAUCRATS ]\033[0m" << std::endl;
	Bureaucrat *bee = new Bureaucrat("Bee", 150);
	Bureaucrat *boo = new Bureaucrat("Boo", 150);
	std::cout << std::endl;

/*======================================================================================================================================*/
/*======================================================================================================================================*/

	std::cout << "\033[35;1m\n[ SHRUBBERY FORM TESTS ]\033[0m" << std::endl;
	std::cout << "\033[35m\n---------Promoting Bureaucrat to Valid Sign Grade--------\033[0m" << std::endl;
	bee->promote(5);

	std::cout << "\033[35m\n---------Cloning--------\033[0m" << std::endl;
	ShrubberyCreationForm *cloneSCF = new ShrubberyCreationForm(*SCF);
	std::cout << std::endl;

	std::cout << "Original SCF: " << SCF;
	std::cout << "Cloned SCF: " << cloneSCF;

	std::cout << "BOO INVALID SIGN GRADE: ";
	cloneSCF->beSigned(boo);
	std::cout << std::endl;

	std::cout << "BEE VALID SIGN GRADE: ";
	cloneSCF->beSigned(bee);
	std::cout << std::endl;

	std::cout << "Original SCF: " << SCF;
	std::cout << "Cloned SCF: " << cloneSCF;

	delete cloneSCF;

	std::cout << "\033[35m\n---------Promoting Bureaucrat to Valid Sign and Execution Grade--------\033[0m" << std::endl;
	std::cout << boo;
	std::cout << bee;

	bee->promote(10); //slightly above execution grade
	boo->promote(10);

	std::cout << "\033[35m\n---------Execution--------\033[0m" << std::endl;
	std::cout << "BOO SIGN FORM: ";
	SCF->beSigned(boo);
	std::cout << std::endl;

	std::cout << "BEE ATTEMPT TO SIGN ALREADY SIGNED FORM: ";
	SCF->beSigned(bee);
	std::cout << std::endl;

	std::cout << "BOO INVALID EXECUTION GRADE: ";
	boo->executeForm(*SCF);
	std::cout << std::endl;
	
	std::cout << "BEE VALID EXECUTION GRADE: ";
	bee->executeForm(*SCF);	
	std::cout << std::endl;

/*======================================================================================================================================*/
/*======================================================================================================================================*/

	std::cout << "\033[35;1m\n[ ROBOTOMY FORM TESTS ]\033[0m" << std::endl;
	std::cout << "\033[35m\n---------Promoting Bureaucrat to Valid Sign Grade--------\033[0m" << std::endl;
	bee->promote(63);

	std::cout << "\033[35m\n---------Cloning--------\033[0m" << std::endl;
	RobotomyRequestForm *cloneRRF = new RobotomyRequestForm(*RRF);
	std::cout << std::endl;

	std::cout << "Original RRF: " << RRF;
	std::cout << "Cloned RRF: " << cloneRRF;

	std::cout << "BOO INVALID SIGN GRADE: ";
	cloneRRF->beSigned(boo);
	std::cout << std::endl;

	std::cout << "BEE VALID SIGN GRADE: ";
	cloneRRF->beSigned(bee);
	std::cout << std::endl;

	std::cout << "Original RRF: " << RRF;
	std::cout << "Cloned RRF: " << cloneRRF;

	delete cloneRRF;

	std::cout << "\033[35m\n---------Promoting Bureaucrat to Valid Sign and Execution Grade--------\033[0m" << std::endl;
	std::cout << boo;
	std::cout << bee;
	std::cout << std::endl;

	bee->promote(27); //execution grade (45)
	boo->promote(70); //sign grade (70)

	std::cout << "\033[35m\n---------Execution--------\033[0m" << std::endl;
	std::cout << "BOO SIGN FORM: ";
	RRF->beSigned(boo);
	std::cout << std::endl;

	std::cout << "BEE ATTEMPT TO SIGN ALREADY SIGNED FORM: ";
	RRF->beSigned(bee);
	std::cout << std::endl;

	std::cout << "BOO INVALID EXECUTION GRADE: ";
	boo->executeForm(*RRF);
	std::cout << std::endl;
	
	std::cout << "BEE VALID EXECUTION GRADE: ";
	bee->executeForm(*RRF);	

/*======================================================================================================================================*/
/*======================================================================================================================================*/

	std::cout << "\033[35;1m\n[ PRESIDENTIAL PARDON FORM TESTS ]\033[0m" << std::endl;
	std::cout << "\033[35m\n---------Promoting Bureaucrat to Valid Sign Grade--------\033[0m" << std::endl;
	boo->promote(45);

	std::cout << "\033[35m\n---------Cloning--------\033[0m" << std::endl;
	PresidentialPardonForm *clonePPF = new PresidentialPardonForm(*PPF);
	std::cout << std::endl;

	std::cout << "Original PPF: " << PPF;
	std::cout << "Cloned PPF: " << clonePPF;

	std::cout << "BEE INVALID SIGN GRADE: ";
	clonePPF->beSigned(bee);
	std::cout << std::endl;

	std::cout << "BOO VALID SIGN GRADE: ";
	clonePPF->beSigned(boo);
	std::cout << std::endl;

	std::cout << "Original PPF: " << PPF;
	std::cout << "Cloned PPF: " << clonePPF;

	delete clonePPF;

	std::cout << "\033[35m\n---------Promoting Bureaucrat to Valid Sign and Execution Grade--------\033[0m" << std::endl;
	std::cout << boo;
	std::cout << bee;
	std::cout << std::endl;

	bee->promote(40); //5

	std::cout << "\033[35m\n---------Execution--------\033[0m" << std::endl;
	std::cout << "BEE SIGN FORM: ";
	PPF->beSigned(bee);
	std::cout << std::endl;

	std::cout << "BOO ATTEMPT TO SIGN ALREADY SIGNED FORM: ";
	PPF->beSigned(boo);
	std::cout << std::endl;

	std::cout << "BOO INVALID EXECUTION GRADE: ";
	boo->executeForm(*PPF);
	std::cout << std::endl;
	
	std::cout << "BEE VALID EXECUTION GRADE: ";
	bee->executeForm(*PPF);	
	std::cout << std::endl;


/*======================================================================================================================================*/
/*======================================================================================================================================*/

	std::cout << "\033[35;1m\n[ DESTRUCTING ]\033[0m" << std::endl;
	delete SCF;
	delete RRF;
	delete PPF;
	delete boo;
	delete bee;
}