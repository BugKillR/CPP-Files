#include "./ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default") {
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " filled with power" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " filled with power" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copied from " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " has been scrapped" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
    {
        std::string oldName = _name;

        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << oldName << " copied the features of " << _name;
		std::cout << ", it's old self has been erased." << std::endl;
    }
    
    return (*this);
}

void        ScavTrap::attack(const std::string& target) {
    if (_hitPoint <= 0) {
		std::cout << "ScavTrap " << _name << " has damaged alot can't attack anymore!" << std::endl;
		return;
	}
	
	if (_energyPoint <= 0) {
		std::cout << "ScavTrap has no energy left" << std::endl;
		return;
	}

	_energyPoint -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void        ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}