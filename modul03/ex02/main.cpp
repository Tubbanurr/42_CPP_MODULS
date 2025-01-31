#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("FragMaster");
    FragTrap frag2("FragWarrior");

    frag1.attack("target1");
    frag2.highFivesGuys();
    std::cout << frag1.getEnergyPoints()<< std::endl;

    FragTrap frag3(frag1);
    frag3.highFivesGuys();

    frag2 = frag1;

    return 0;
}
