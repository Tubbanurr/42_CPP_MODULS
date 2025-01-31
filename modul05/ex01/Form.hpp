#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };

        Form();
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat& b);

        std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
