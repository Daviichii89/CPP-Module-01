#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

void Weapon::setType(const std::string& newType) {
    type = newType;
}

const std::string& Weapon::getType() {
    return type;
}
