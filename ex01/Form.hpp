#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form(const std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();
    Form &operator=(const Form &other);

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif 