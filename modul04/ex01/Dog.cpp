#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
    type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*copy.brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete brain;
        brain = new Brain(*copy.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}
