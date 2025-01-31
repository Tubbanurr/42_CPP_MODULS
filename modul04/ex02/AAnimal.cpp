#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") 
{
    std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type) 
{
    std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) 
{
    std::cout << "AAnimal assignment operator called." << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

std::string AAnimal::getType() const
{
    return type;
}
