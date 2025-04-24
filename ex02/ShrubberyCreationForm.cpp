#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", requiredGradeToSign, requiredGradeToExecute), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", requiredGradeToSign, requiredGradeToExecute), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) 
    : AForm(src), _target(src._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecutionRequirements(executor);
    
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile) {
        std::cerr << "Error: could not create file " << filename << std::endl;
        return;
    }
    
    outfile << "         v" << std::endl;
    outfile << "        >X<" << std::endl;
    outfile << "         A" << std::endl;
    outfile << "        d$b" << std::endl;
    outfile << "      .d\\$$b." << std::endl;
    outfile << "    .d$i$$\\$$b." << std::endl;
    outfile << "       d$$@b" << std::endl;
    outfile << "      d\\$$$ib" << std::endl;
    outfile << "    .d$$$\\$$$b" << std::endl;
    outfile << "  .d$$@$$$$\\$$ib." << std::endl;
    outfile << "      d$$i$$b" << std::endl;
    outfile << "     d\\$$$$@$b" << std::endl;
    outfile << "  .d$@$$\\$$$$$@b." << std::endl;
    outfile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
    outfile << "        ###" << std::endl;
    outfile << "        ###" << std::endl;
    outfile << "        ###" << std::endl;
    
    outfile.close();
    std::cout << "Created shrubbery file: " << filename << std::endl;
}