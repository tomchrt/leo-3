#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", requiredGradeToSign, requiredGradeToExecute), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", requiredGradeToSign, requiredGradeToExecute), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) 
    : AForm(src), _target(src._target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecutionRequirements(executor);
    
    std::cout << "* DRILLING NOISES *" << std::endl;
    
    std::srand(std::time(0));
    
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
    }
}