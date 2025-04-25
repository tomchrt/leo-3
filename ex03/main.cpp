#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "--- Testing Intern ---" << std::endl;
        
        Intern someRandomIntern;
        Bureaucrat boss("Big Boss", 1);
        
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
        
        std::cout << "\n--- Testing created forms ---" << std::endl;
        
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        
        boss.signForm(*scf);
        boss.executeForm(*scf);
        
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        
        std::cout << "\n--- Testing non-existent form ---" << std::endl;
        try {
            AForm* nonExistentForm = someRandomIntern.makeForm("coffee making", "Coffee Machine");
            (void)nonExistentForm; // To avoid unused variable warning
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
        delete rrf;
        delete scf;
        delete ppf;
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}