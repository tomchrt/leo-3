#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", requiredGradeToSign, requiredGradeToExecute), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", requiredGradeToSign, requiredGradeToExecute), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) 
    : AForm(src), _target(src._target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecutionRequirements(executor);
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}