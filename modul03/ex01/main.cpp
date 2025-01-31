#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ClapTrap clap1("ClapMaster");
    clap1.attack("Target1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    ScavTrap scav1("ScavBoss");
    scav1.attack("Target2");
    scav1.takeDamage(30);
    scav1.beRepaired(20);
    scav1.guardGate();
    ScavTrap scav2(scav1);
    ScavTrap scav3("AnotherScav");
    scav3 = scav2;

    return 0;
}
