#include "FragTrap.hpp"

FragTrap::FragTrap(){};

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FRAGTRAP " << name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FRAGTRAP " << _name << " has been copied!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FRAGTRAP " << _name << " has been destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    if (this != &copy)
        ClapTrap::operator=(copy);
    std::cout << "FRAGTRAP " << copy.getName() << " has been assigned!" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "FRAGTRAP " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
         std::cout << "FRAGTRAP " << _name << " cannot attack, no hit points or energy left!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FRAGTRAP " << _name << " is requesting a high five!" << std::endl;
}
