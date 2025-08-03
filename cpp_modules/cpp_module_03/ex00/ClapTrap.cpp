#include "ClapTrap.hpp"



ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    name = "";
    hitPoints = 10;
    energyPoints= 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string str)
{
    std::cout << "name constructor called" << std::endl;
    name = str;
    hitPoints = 10;
    energyPoints= 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints= other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std:: cout << "Copy assignment operator called" << std::endl;
    if (this == &other) 
        return *this;
    name = other.getName();
    hitPoints = other.getHitPoints();
    energyPoints= other.getEnergyPoints();
    attackDamage = other.getAttackDamage();
    return (*this);
}


ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target
                    << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or is destroyed and cannot attack.\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name << " suffers " << amount
                << " points of damage! Remaining HP: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;

        std::cout << "ClapTrap " << name << " repairs itself for "
                    << amount << " points! Current HP: " << hitPoints
                    << ", Energy: " << energyPoints << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " can't repair (no energy or destroyed).\n";
    }
}

void ClapTrap::printData(void) const
{
    std::cout << "--------PRINTING DATA---------" << std::endl;
    std::cout << "name : " << name << std::endl
            << "hitPoints: " << hitPoints << std::endl
            << "energyPoints: " << energyPoints << std::endl
            << "attackDamage: " << attackDamage << std::endl;
    std::cout << "-----------------------------" << std::endl;

}

std::string ClapTrap::getName() const
{
    return (name);
}
int ClapTrap::getHitPoints() const
{
    return (hitPoints);
}
int ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}
int ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}
void ClapTrap::setAttackDamage(int attackDamage)
{
    this->attackDamage = attackDamage;
}