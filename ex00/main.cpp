#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        // Test constructeur normal
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;

        // Test increment
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        // Test decrement
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

        // Test grade trop haut
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test grade trop bas
        Bureaucrat tooLow("TooLow", 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test increment à la limite
        Bureaucrat high("High", 1);
        std::cout << high << std::endl;
        high.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test decrement à la limite
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
        low.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
