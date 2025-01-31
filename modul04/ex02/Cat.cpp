#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << "Cat constructor called" << std::endl;
    brain = new Brain();
    type = "Cat";
}

Cat::Cat(const Cat& copy) : AAnimal(copy) 
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*copy.brain);
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat& Cat::operator=(const Cat& copy) 
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &copy) 
    {
        AAnimal::operator=(copy);
        delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << "Meow!" << std::endl;
}
