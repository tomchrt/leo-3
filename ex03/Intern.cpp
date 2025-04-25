#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern::~Intern() {
}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (Intern::*forms[3])(const std::string&) const = {
        &Intern::makeShrubberyForm,
        &Intern::makeRobotomyForm,
        &Intern::makePresidentialForm
    };
    
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*forms[i])(target);
        }
    }
    
    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}

AForm* Intern::makeShrubberyForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
