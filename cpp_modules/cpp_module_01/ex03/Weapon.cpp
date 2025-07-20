#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

// Getter method returning const reference
const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& newType) {
    this->type = newType;
}