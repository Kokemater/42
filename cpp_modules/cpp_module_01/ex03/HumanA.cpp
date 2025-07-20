#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    this->name = name;
    this->weapon = weapon;
}

void HumanA::attack(void) const
{
    std::cout << name << "attacks with their " << weapon << std::endl;
}