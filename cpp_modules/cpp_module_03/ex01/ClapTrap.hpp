#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap();                                         // Default constructor
    ClapTrap(const std::string str);                   // name constructor
    ClapTrap(const ClapTrap &other);                  // copy constructor
    ClapTrap& operator=(const ClapTrap &other);      // copy assignment operator
    virtual ~ClapTrap();                            // destructor
    void printData() const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;
    void setAttackDamage(int attackDamage);

    virtual void attack(const std::string& target);

};

#endif