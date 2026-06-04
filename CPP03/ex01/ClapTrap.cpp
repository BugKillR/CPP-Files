#include "./ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0) { 
	std::cout << "ClapTrap " << _name << " filled with power" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " filled with power" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other._name;
	_hitPoint = other._hitPoint;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap copied from " << _name << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been scrapped" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
		std::string oldName = _name;

		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << oldName << " copied the features of " << _name;
		std::cout << ", it's old self has been erased." << std::endl;
	}
	return (*this);
}

void		ClapTrap::attack(const std::string& target) {
	if (_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name << " has damaged alot can't attack anymore!" << std::endl;
		return;
	}
	
	if (_energyPoint <= 0) {
		std::cout << "ClapTrap has no energy left" << std::endl;
		return;
	}

	_energyPoint -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= static_cast<unsigned int>(_hitPoint)) {
		_hitPoint = 0;
		std::cout << "ClapTrap " << _name << " has damaged alot can't move anymore!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " had " << _hitPoint << ", ";
		_hitPoint -= amount; 
		std::cout << "updated hit-point is " << _hitPoint << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name << " has damaged alot can't be repaired anymore!" << std::endl;
		return ;
	}
	
	if (_energyPoint <= 0) {
		std::cout << "ClapTrap has no energy left" << std::endl;
		return;
	}

	_energyPoint -= 1;
	
	std::cout << "ClapTrap " << _name << " had " << _hitPoint << ", ";
	_hitPoint += amount;
	std::cout << "updated hit-point is " << _hitPoint << std::endl;
}
