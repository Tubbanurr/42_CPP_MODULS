#include "ShrubberyCreationForm.hpp"

// Kurucu Metotlar
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute Metodu
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "        ccee88oo" << std::endl;
        outfile << "      C8O8O8Q8PoOb o8oo" << std::endl;
        outfile << "   dOB69QO8PdUOpugoO9bD" << std::endl;
        outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
        outfile << "    6OuU  /p u gcoUodpP" << std::endl;
        outfile << "      \\//  /douUP" << std::endl;
        outfile << "        \\////" << std::endl;
        outfile << "         |||/" << std::endl;
        outfile << "         |||" << std::endl;
        outfile << "         |||" << std::endl;
        outfile << "   , -=-~  .-^- _" << std::endl;
        outfile.close();
    }
}