#include "iter.hpp"

template <typename T>
void printElement(const T &elem) {
    std::cout << elem << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Integer array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "Templates"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}