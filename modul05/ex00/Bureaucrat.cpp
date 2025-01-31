#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

// Kurucu Metot
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Kopya Kurucu
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Atama Operatörü
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

// Yıkıcı Metot
Bureaucrat::~Bureaucrat() {}

// Getter Metotlar
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Dereceyi Artırma
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// Dereceyi Azaltma
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// İstisna Mesajları
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Çıktı Operatörü
std::ostream& Bureaucrat::print(std::ostream& os) const {
    os << _name << ", bureaucrat grade " << _grade << ".";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    return b.print(os);
}
