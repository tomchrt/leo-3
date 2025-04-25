#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& src);
    ~Intern();
    
    Intern& operator=(const Intern& rhs);
    
    AForm* makeForm(const std::string& formName, const std::string& target);
    
    AForm* makeShrubberyForm(const std::string& target) const;
    AForm* makeRobotomyForm(const std::string& target) const;
    AForm* makePresidentialForm(const std::string& target) const;
    
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif