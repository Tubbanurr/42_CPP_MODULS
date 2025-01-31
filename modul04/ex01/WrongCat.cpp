#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) 
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) 
{
    if (this != &copy)
        WrongAnimal::operator=(copy);
    std::cout << "WrongCat assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const 
{
    std::cout << "Wrong Meow!" << std::endl;
}
