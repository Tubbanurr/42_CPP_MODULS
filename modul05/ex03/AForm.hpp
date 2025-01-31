#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    protected:
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

        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
        };

        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
