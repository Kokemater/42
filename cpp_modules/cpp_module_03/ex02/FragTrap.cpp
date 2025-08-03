#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    name = "";
    hitPoints = 100;
    energyPoints= 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string str)
{
    std::cout << "name FragTrap constructor called" << std::endl;
    name = str;
    hitPoints = 100;
    energyPoints= 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "Copy FragTrap constructor called" << std::endl;
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints= other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std:: cout << "Copy FragTrap assignment operator called" << std::endl;
    if (this == &other) 
        return *this;
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints= other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target
                    << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << name << " has no energy or is destroyed and cannot attack.\n";
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap" << name <<" wants high five" << std::endl;
}
