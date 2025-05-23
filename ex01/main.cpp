#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Tax Form", 40, 30);
        Form form2("Simple Form", 100, 90);

        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        bob.signForm(form2);
        bob.signForm(form1);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        try {
            Form invalidForm("Invalid", 0, 30);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Form invalidForm2("Invalid2", 151, 30);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Form form3(form2);
        std::cout << "Original: " << form2 << std::endl;
        std::cout << "Copy: " << form3 << std::endl;

    } catch (std::exception &e) {
        std::cout << "Main exception: " << e.what() << std::endl;
    }

    return 0;
}
