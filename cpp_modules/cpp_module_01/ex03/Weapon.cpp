#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : type(type) {}

// Getter method returning const reference
const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& newType) {
    this->type = newType;
}

std::ostream& operator<<(std::ostream& out, const Weapon& obj) {
    out << obj.getType();
    return out;
}