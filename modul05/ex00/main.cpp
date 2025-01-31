#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade(); // Derece 1 olmalı
        std::cout << b1 << std::endl;
        b1.incrementGrade(); // Burada hata vermeli
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade(); // Derece 150 olmalı
        std::cout << b2 << std::endl;
        b2.decrementGrade(); // Burada hata vermeli
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151); // Başlangıçta hata vermeli
        std::cout << b3 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
