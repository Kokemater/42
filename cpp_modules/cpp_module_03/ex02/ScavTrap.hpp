#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
class ScavTrap : public ClapTrap {

public:
    ScavTrap();                                         // Default constructor
    ScavTrap(const std::string str);                   // name constructor
    ScavTrap(const ScavTrap &other);                  // copy constructor
    ScavTrap& operator=(const ScavTrap &other);      // copy assignment operator
    ~ScavTrap();                                    // destructor
    void attack(const std::string& target);
    void guardGate();
};

#endif