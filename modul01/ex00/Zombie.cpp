#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : Name(name)
{
	std::cout << Name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << Name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
