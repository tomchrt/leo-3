#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "--- Testing Concrete Forms ---" << std::endl;
        
        // Create bureaucrats with different grades
        Bureaucrat lowGrade("Intern", 140);
        Bureaucrat midGrade("Manager", 40);
        Bureaucrat highGrade("Director", 3);
        
        std::cout << lowGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << highGrade << std::endl;
        
        // Create forms
        ShrubberyCreationForm shrubberyForm("garden");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Criminal");
        
        std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
        std::cout << shrubberyForm << std::endl;
        
        // Intern can sign but not execute
        lowGrade.signForm(shrubberyForm);
        lowGrade.executeForm(shrubberyForm);
        
        // Manager can both sign and execute
        midGrade.executeForm(shrubberyForm);
        
        std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
        std::cout << robotomyForm << std::endl;
        
        // Intern cannot sign
        lowGrade.signForm(robotomyForm);
        
        // Manager can sign but not execute without signature
        midGrade.executeForm(robotomyForm);
        midGrade.signForm(robotomyForm);
        midGrade.executeForm(robotomyForm);
        
        std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
        std::cout << pardonForm << std::endl;
        
        // Manager cannot sign
        midGrade.signForm(pardonForm);
        
        // Director can sign and execute
        highGrade.signForm(pardonForm);
        highGrade.executeForm(pardonForm);
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}