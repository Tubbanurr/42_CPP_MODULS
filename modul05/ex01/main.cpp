#include "Bureaucrat.hpp"
#include "Form.hpp"

void testSigning(Bureaucrat& bureaucrat, Form& form) {
    std::cout << "-------------------------------" << std::endl;
    std::cout << bureaucrat << std::endl;
    std::cout << form << std::endl;
    try {
        bureaucrat.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << form << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

int main() {
    Bureaucrat highRank("Alice", 2);
    Bureaucrat lowRank("Bob", 100);
    
    Form importantForm("Top Secret", 10, 5);
    Form easyForm("Simple Form", 120, 100);

    testSigning(highRank, importantForm);
    testSigning(lowRank, easyForm);
    testSigning(lowRank, importantForm); // Beklenen: hata fırlatılmalı
    
    return 0;
}
