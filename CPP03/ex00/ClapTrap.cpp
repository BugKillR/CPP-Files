#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoint(10), _energyPoint(10), _attackDamage(0), _status(ALIVE) { }

ClapTrap::ClapTrap(const ClapTrap& other) {
	setName(other.getName());
	setHitPoint(other.getHitPoint());
	setEnergyPoint(other.getEnergyPoint());
	setAttackDamage(other.getAttackDamage());
	setStatus(other.getStatus());
}

ClapTrap::~ClapTrap() { }

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	setName(other.getName());
	setHitPoint(other.getHitPoint());
	setEnergyPoint(other.getEnergyPoint());
	setAttackDamage(other.getAttackDamage());
	setStatus(other.getStatus());
	return (*this);
}

std::string	ClapTrap::getName(void) const { return _name; }
int			ClapTrap::getHitPoint(void) const { return _hitPoint; }
int			ClapTrap::getEnergyPoint(void) const { return _energyPoint; }
int			ClapTrap::getAttackDamage(void) const { return _attackDamage; }
Status		ClapTrap::getStatus(void) const { return _status; }

void		ClapTrap::setName(std::string name) { _name = name; }
void		ClapTrap::setHitPoint(int hitPoint) { _hitPoint = hitPoint; }
void		ClapTrap::setEnergyPoint(int energyPoint) { _energyPoint = energyPoint; }
void		ClapTrap::setAttackDamage(int attackDamage) { _attackDamage = attackDamage; }
void		ClapTrap::setStatus(Status status) {
	switch (status)
	{
		case ALIVE:
			_status = status;
			break;
		case DEAD:
			_status = status;
			break;
		default:
			std::cout << "Status not exist!" << std::endl;
	}
}

void		ClapTrap::attack(const std::string& target) {
	if (getStatus() == DEAD)
		return ;

	if (getEnergyPoint() <= 0) {
		std::cout << getName() << " out of energy" << std::endl;
		return ;
	}

	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << getModel() << " " << getName() << " attacks " << target;
	std::cout << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (getStatus() == DEAD)
		return ;
	
	if (amount >= (unsigned int)getHitPoint()) {
		std::cout << getModel() << " " << getName() << " got hit by " << amount << " point of damage" << std::endl;
		std::cout << getModel() << " " << getName() << " is killed" << std::endl;
		setHitPoint(0);
		setStatus(DEAD);
		return ;
	}
	else
	{
		setHitPoint((unsigned int)getHitPoint() - amount);
		std::cout << getModel() << " " << getName() << " got hit by " << amount << " point of damage, ";
		std::cout << "has " << getHitPoint() <<  " hitpoint left" << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (getStatus() == DEAD)
		return ;
	
	if (getEnergyPoint() <= 0) {
		std::cout << getModel() << " " << getName() << " out of energy" << std::endl;
		return ;
	}

	setEnergyPoint(getEnergyPoint() - 1);
	
	if ((unsigned int)getHitPoint() + amount >= 10) {
		std::cout  << getModel() << " " << getName() << " repaired " << (unsigned int)getHitPoint() + amount - 10 << " hitpoints, ";
		setHitPoint(10);
		std::cout << "current hitpoint is " << getHitPoint() << std::endl;
	}
	else {
		std::cout << getModel() << " " << getName() << " repaired " << amount << " hitpoints, ";
		setHitPoint((unsigned int)getHitPoint() + amount);
		std::cout << "current hitpoint is " << getHitPoint() << std::endl;
	}
}