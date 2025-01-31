#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "CLAPTRAP default constructor called" << std::endl;

};

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "CLAPTRAP " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "CLAPTRAP copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "CLAPTRAP " << _name << " has been destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << "CLAPTRAP assignation operator called" << std::endl;
    if (this != &copy)
    {
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}

void ClapTrap::setName(std::string name)
{
    _name = name;
}
void ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(int energyPoints)
{
    _energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(int attackDamage)
{
    _attackDamage = attackDamage;
}

std::string ClapTrap::getName() const
{
    return _name;
}
int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}
int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}
int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "CLAPTRAP " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "CLAPTRAP " << _name << " cannot attack, no energy or hit points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints = ((int)amount >= _hitPoints) ? 0 : _hitPoints - amount;
    std::cout << "CLAPTRAP " << _name << " took " << amount
              << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "CLAPTRAP " << _name << " is repaired by " << amount
                  << " hit points! New hit points: " << _hitPoints << std::endl;
    }
    else
        std::cout << "CLAPTRAP " << _name << " cannot repair itself, no energy or hit points left!" << std::endl;
}
