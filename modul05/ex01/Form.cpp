#include "Form.hpp"

// Kurucu Metotlar
Form::Form() : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

// Getter Metotlar
const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

// İmzalama Metodu
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// İstisna Mesajları
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Çıktı Operatörü
std::ostream& Form::print(std::ostream& os) const {
    os << "Form " << _name << " (Sign Grade: " << _signGrade << ", Exec Grade: " << _execGrade << ") is ";
    os << (_isSigned ? "signed." : "not signed.");
    return os;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    return f.print(os);
}
