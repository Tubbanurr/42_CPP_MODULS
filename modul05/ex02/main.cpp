#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testSigningAndExecution(Bureaucrat& bureaucrat, AForm& form) {
    std::cout << "\n===============================" << std::endl;
    std::cout << "Testing " << form.getName() << " with " << bureaucrat.getName() << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << bureaucrat << std::endl;
    std::cout << form << std::endl;
    
    try {
        bureaucrat.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception while signing: " << e.what() << std::endl;
    }
    
    try {
        bureaucrat.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception while executing: " << e.what() << std::endl;
    }

    std::cout << "===============================\n" << std::endl;
}

int main() {
    Bureaucrat highRank("Alice", 1);
    Bureaucrat midRank("Bob", 50);
    Bureaucrat lowRank("Charlie", 150);
    
    ShrubberyCreationForm shrubbery("Garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");
    
    std::cout << "\n***** FORM SIGNING & EXECUTION TESTS *****\n" << std::endl;
    
    // High-rank bureaucrat executes all forms
    testSigningAndExecution(highRank, shrubbery);
    testSigningAndExecution(highRank, robotomy);
    testSigningAndExecution(highRank, pardon);
    
    // Mid-rank bureaucrat attempts execution
    testSigningAndExecution(midRank, shrubbery);
    testSigningAndExecution(midRank, robotomy);
    testSigningAndExecution(midRank, pardon);
    
    // Low-rank bureaucrat fails to sign and execute
    testSigningAndExecution(lowRank, shrubbery);
    testSigningAndExecution(lowRank, robotomy);
    testSigningAndExecution(lowRank, pardon);
    
    return 0;
}