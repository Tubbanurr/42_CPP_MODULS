#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("ClapMaster");
    ClapTrap clap2("ClapWarrior");

    std::cout << "---- Attack Test ----" << std::endl;
    clap1.attack("ClapWarrior");
    clap2.takeDamage(3);

    std::cout << "\n---- Boundary Test ----" << std::endl;
    clap2.attack("ClapMaster");
    clap1.takeDamage(8);
    clap1.beRepaired(5);
    std::cout << "energy:" << clap1.getEnergyPoints() << std::endl;

    std::cout << "\n---- Energy Depletion Test ----" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        clap1.attack("ClapWarrior");
        clap1.beRepaired(1);
    }

    std::cout << "\n---- No Energy Left ----" << std::endl;
    clap1.attack("ClapWarrior");
    clap1.beRepaired(2);

    std::cout << "\n---- Full Damage Test ----" << std::endl;
    clap2.takeDamage(15);
    clap2.attack("ClapMaster");

    std::cout << "\n---- No Hit Points Left ----" << std::endl;
    clap2.beRepaired(5);

    return 0;
}
