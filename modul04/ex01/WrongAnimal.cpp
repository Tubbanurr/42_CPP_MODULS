#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type) 
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) 
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const 
{
    return this->type;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "WrongAnimal makes a weird sound..." << std::endl;
}
