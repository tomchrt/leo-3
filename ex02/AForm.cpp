#include "AForm.hpp"

AForm::AForm() 
    : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : _name(src._name), _signed(src._signed), 
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

AForm::~AForm() {
}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        // Cannot copy const attributes
        _signed = rhs._signed;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();
}

void AForm::checkExecutionRequirements(Bureaucrat const & executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& o, const AForm& form) {
    o << "Form " << form.getName() 
      << ", signed: " << (form.isSigned() ? "yes" : "no") 
      << ", grade to sign: " << form.getGradeToSign() 
      << ", grade to execute: " << form.getGradeToExecute();
    return o;
}