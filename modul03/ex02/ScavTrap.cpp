#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){};

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "SCAVTRAP " << name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap&copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "SCAVTRAP " << _name << " has been copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    if (this != &copy)
        ClapTrap::operator=(copy);
    std::cout << "SCAVTRAP " << _name << " has been assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "SCAVTRAP " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "SCAVTRAP " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
         std::cout << "SCAVTRAP " << _name << " cannot attack, no hit points or energy left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "SCAVTRAP " << _name << " is now in Gatekeeper mode!" << std::endl;
}
