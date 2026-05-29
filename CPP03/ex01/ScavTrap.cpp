#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	setModel("ScavTrap"); 
	this->_name = "Bora";
	this->_hitPoint = 100;
	this->_maxHitpoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_status = ALIVE;
	_protection = OFF;
}

ScavTrap::ScavTrap(std::string model, std::string name) : ClapTrap(model, name) {
	this->_hitPoint = 100;
	this->_maxHitpoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_status = ALIVE;
	_protection = OFF;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) { }

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) { 
	if (this != &other) {
		ClapTrap::operator=(other);
		setProtection(other.getProtection());
	}

	return (*this);
}

ScavTrap::~ScavTrap() { }

Protection	ScavTrap::getProtection(void) const { return _protection; }
void		ScavTrap::setProtection(Protection protection) { _protection = protection; }

void		ScavTrap::takeDamage(unsigned int amount) {
	if (getProtection() == ON) {
		std::cout << getModel() << " " << getName() << " absorbed " << amount << " damage with shield, shileds OFF" << std::endl;
		setProtection(OFF);

		return ;
	}

	ClapTrap::takeDamage(amount);
}

void		ScavTrap::guardGate() {
	std::cout << getModel() << " " << getName() << " used Guard Gate ability, shields ON" << std::endl;
	setProtection(ON);
}
