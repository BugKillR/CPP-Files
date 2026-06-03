#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), name("default") {
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << name << " filled with power" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << name << " filled with power" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "DiamondTrap copied from " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " has been scrapped" << std::endl;
}

void		DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI() {
	std::cout << "My DiamondTrap name is " << name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}