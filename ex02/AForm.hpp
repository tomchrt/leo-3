#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& src);
    virtual ~AForm();
    
    AForm& operator=(const AForm& rhs);
    
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Pure virtual function to make the class abstract
    virtual void execute(Bureaucrat const & executor) const = 0;
    // Helper method to check execution requirements
    void checkExecutionRequirements(Bureaucrat const & executor) const;
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif