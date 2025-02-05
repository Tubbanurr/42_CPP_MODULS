#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) 
{
    std::cout << "Input: " << literal << std::endl;

    if (literal == "nan" || literal == "nanf") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    } 
    if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "inff" || literal == "+inff" || literal == "-inff") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);

        if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") 
        {
            std::cout << "float: " << std::numeric_limits<float>::max() << "f" << std::endl;
            std::cout << "double: " << std::numeric_limits<double>::max() << std::endl;
        } 
        else
        {
            std::cout << "float: " << -std::numeric_limits<float>::max() << "f" << std::endl;
            std::cout << "double: " << -std::numeric_limits<double>::max() << std::endl;
        }
        return;
    }

    double value;
    std::istringstream iss(literal);
    
    if (!(iss >> value)) {
        std::cout << "Invalid input!" << std::endl;
        return;
    }

    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: inff" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << std::endl;
    std::cout << std::scientific << std::setprecision(6);
    std::cout << "double(scientific): " << value << std::endl;
}
