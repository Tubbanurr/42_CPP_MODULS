#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::setName(const std::string& name) {
    _name = name;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
