#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type) 
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const 
{
    return this->type;
}

void Animal::makeSound() const 
{
    std::cout << "Animal makes a sound..." << std::endl;
}
