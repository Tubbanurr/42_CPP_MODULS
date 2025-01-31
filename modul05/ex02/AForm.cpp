#include "AForm.hpp"

// Kurucu Metotlar
AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

// Getter Metotlar
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

// İmzalama Metodu
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// İstisna Mesajları
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Çıktı Operatörü
std::ostream& AForm::print(std::ostream& os) const {
    os << "Form " << _name << " (Sign Grade: " << _signGrade << ", Exec Grade: " << _execGrade << ") is ";
    os << (_isSigned ? "signed." : "not signed.");
    return os;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    return f.print(os);
}
