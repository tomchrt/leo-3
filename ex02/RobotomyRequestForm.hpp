#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();
    
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    
    void execute(Bureaucrat const & executor) const;
    
    static const int requiredGradeToSign = 72;
    static const int requiredGradeToExecute = 45;
};

#endif