#ifndef FRAGTRA_HPP
# define FRAGTRA_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& copy);
        ~FragTrap();

        FragTrap& operator=(const FragTrap& copy);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
