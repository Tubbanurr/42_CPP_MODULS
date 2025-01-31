#include "PresidentialPardonForm.hpp"

// Kurucu Metotlar
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Execute Metodu
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}