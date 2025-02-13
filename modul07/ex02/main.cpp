#include "Array.hpp"

int main() 
{
    try {
        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); i++) 
            intArray[i] = static_cast<int>(i * 2);

        std::cout << "Integer array: ";
        for (size_t i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "C++";

        std::cout << "String array: ";
        for (size_t i = 0; i < strArray.size(); i++)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;

        std::cout << "Trying to access out of bounds index..." << std::endl;
        std::cout << intArray[10] << std::endl;

    } 
    catch (const std::exception& e)
    { 
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
