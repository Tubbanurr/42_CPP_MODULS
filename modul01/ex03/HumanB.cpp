#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){}

void HumanB::setWeapon(const Weapon &weapon)
{
	this->_weapon = (Weapon *)&weapon;
}

void HumanB::attack() const
{
	if (this->_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;

}
