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

    //tests for orthodoxal-cannonical-form
    ClapTrap ct_default;
    ct_default.printData();
    ClapTrap ct1 = ct;
    ClapTrap ct2(ct);
    ct.printData();
    ct1.printData();
    ct2.printData();
    std::cout << "=============================" << std::endl;

    return 0;
}
