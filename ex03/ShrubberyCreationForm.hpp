#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();
    
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    
    void execute(Bureaucrat const & executor) const;
    
    static const int requiredGradeToSign = 145;
    static const int requiredGradeToExecute = 137;
};

#endif