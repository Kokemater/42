#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    name = "";
    hitPoints = 100;
    energyPoints= 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string str)
{
    std::cout << "name ScavTrap constructor called" << std::endl;
    name = str;
    hitPoints = 100;
    energyPoints= 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "Copy ScavTrap constructor called" << std::endl;
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints= other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std:: cout << "Copy ScavTrap assignment operator called" << std::endl;
    if (this == &other) 
        return *this;
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints= other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target
                    << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << name << " has no energy or is destroyed and cannot attack.\n";
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
