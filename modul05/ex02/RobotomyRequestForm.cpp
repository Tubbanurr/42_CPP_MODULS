#include "RobotomyRequestForm.hpp"

// Kurucu Metotlar
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute Metodu
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    
    std::cout << "Bzzzt... Drilling noises..." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2) {
        std::cout << _target << " has been successfully robotomized!" << std::endl;
    } else {
        std::cout << "The robotomy on " << _target << " failed!" << std::endl;
    }
}
