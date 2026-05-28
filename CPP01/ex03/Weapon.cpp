#include "./Weapon.hpp"

Weapon::Weapon() : _type("knuckleduster") { }

Weapon::Weapon(std::string weaponType) { _type = weaponType; }

Weapon::~Weapon() { }

std::string Weapon::getType() const { return _type; }

void        Weapon::setType(std::string type) { _type = type; }
