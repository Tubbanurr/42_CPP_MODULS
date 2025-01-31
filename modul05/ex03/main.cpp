#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Stajyerin form oluşturma yeteneğini test eden fonksiyon
void testInternFormCreation(Intern& intern, const std::string& formName, const std::string& target) {
    std::cout << "\n===============================" << std::endl;
    std::cout << "Intern attempting to create form: " << formName << std::endl;
    AForm* form = intern.makeForm(formName, target);
    
    if (form) {
        std::cout << "Successfully created form:\n" << *form << std::endl;
        delete form;  // Bellek sızıntısını önlemek için
    } else {
        std::cout << "Failed to create form: " << formName << std::endl;
    }
    std::cout << "===============================\n" << std::endl;
}

// Form imzalama ve yürütme sürecini test eden fonksiyon
void testFormSigningAndExecution(Bureaucrat& bureaucrat, AForm& form) {
    std::cout << "\n===============================" << std::endl;
    std::cout << "Bureaucrat: " << bureaucrat.getName() << " (Grade: " << bureaucrat.getGrade() << ") attempting to sign and execute:" << std::endl;
    std::cout << form << std::endl;

    try {
        bureaucrat.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Error while signing: " << e.what() << std::endl;
    }

    try {
        bureaucrat.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Error while executing: " << e.what() << std::endl;
    }

    std::cout << "===============================\n" << std::endl;
}

int main() {
    Intern intern;
    Bureaucrat boss("Alice", 1);  // En yüksek yetkili bürokrat
    Bureaucrat midLevel("Bob", 45);  // Orta seviye bürokrat
    Bureaucrat lowLevel("Charlie", 150);  // En düşük seviye bürokrat

    // Intern tarafından form oluşturma testleri
    AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
    AForm* robotomyForm = intern.makeForm("robotomy request", "Bender");
    AForm* pardonForm = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm* unknownForm = intern.makeForm("unknown form", "Test Target");

    // Geçerli formların imzalanması ve yürütülmesi
    if (shrubberyForm) {
        testFormSigningAndExecution(boss, *shrubberyForm);
    }
    if (robotomyForm) {
        testFormSigningAndExecution(midLevel, *robotomyForm);
    }
    if (pardonForm) {
        testFormSigningAndExecution(lowLevel, *pardonForm);
    }

    // Yetkisiz form yürütme testi
    if (pardonForm) {
        std::cout << "\nAttempting to execute 'Presidential Pardon' with insufficient authority..." << std::endl;
        testFormSigningAndExecution(midLevel, *pardonForm);  // Bob yetkisiz
    }

    // Belleği temizleme
    delete shrubberyForm;
    delete robotomyForm;
    delete pardonForm;
    delete unknownForm;

    return 0;
}
