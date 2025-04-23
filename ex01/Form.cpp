#include "Form.hpp"
#include <iostream>

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName() 
       << ", signing grade " << form.getGradeToSign()
       << ", execution grade " << form.getGradeToExecute()
       << ", is " << (form.getIsSigned() ? "signed" : "not signed");
    return os;
} 