#include "Identify.hpp"
#include <ctime>

int main() {
    std::srand(std::time(0));

    Base* obj = generate();
    std::cout << "Identifying using pointer:" << std::endl;
    identify(obj);

    std::cout << "Identifying using reference:" << std::endl;
    identify(*obj);

    delete obj;
    return 0;
}
