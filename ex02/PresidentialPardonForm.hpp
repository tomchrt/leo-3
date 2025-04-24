#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();
    
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    
    void execute(Bureaucrat const & executor) const;
    
    static const int requiredGradeToSign = 25;
    static const int requiredGradeToExecute = 5;
};

#endif