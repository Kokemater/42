#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
class FragTrap : public ClapTrap {

public:
    FragTrap();                                         // Default constructor
    FragTrap(const std::string str);                   // name constructor
    FragTrap(const FragTrap &other);                  // copy constructor
    FragTrap& operator=(const FragTrap &other);      // copy assignment operator
    ~FragTrap();                                    // destructor
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif