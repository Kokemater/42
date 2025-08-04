#include "ClapTrap.hpp"

int main()
{
    std::cout << "=============================" << std::endl;

    // tests for subject
    ClapTrap ct("Moraleda");
    ct.setAttackDamage(10);
    ct.printData();
    ct.attack("buitre");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.takeDamage(8);
    ct.attack("busardo");

    std::cout << "=============================" << std::endl;

    return 0;
}
