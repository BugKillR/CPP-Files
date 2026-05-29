#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : _model("Unset"), _name("Kayra"), _hitPoint(10), _maxHitpoint(10), _energyPoint(10), _attackDamage(0), _status(ALIVE) { }

ClapTrap::ClapTrap(std::string model, std::string name) : _model(model), _name(name), _hitPoint(10), _maxHitpoint(10), _energyPoint(10), _attackDamage(0), _status(ALIVE) { }

ClapTrap::ClapTrap(const ClapTrap& other) {
	setName(other.getName());
	setHitPoint(other.getHitPoint());
	setMaxHitPoint(other.getMaxHitPoint());
	setEnergyPoint(other.getEnergyPoint());
	setAttackDamage(other.getAttackDamage());
	setStatus(other.getStatus());
	setModel(other.getModel());
}

ClapTrap::~ClapTrap() { }

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	setName(other.getName());
	setHitPoint(other.getHitPoint());
	setMaxHitPoint(other.getMaxHitPoint());
	setEnergyPoint(other.getEnergyPoint());
	setAttackDamage(other.getAttackDamage());
	setStatus(other.getStatus());
	setModel(other.getModel());
	return (*this);
}

std::string	ClapTrap::getName(void) const { return _name; }
int			ClapTrap::getHitPoint(void) const { return _hitPoint; }
int			ClapTrap::getMaxHitPoint(void) const { return _maxHitpoint; }
int			ClapTrap::getEnergyPoint(void) const { return _energyPoint; }
int			ClapTrap::getAttackDamage(void) const { return _attackDamage; }
Status		ClapTrap::getStatus(void) const { return _status; }
std::string	ClapTrap::getModel(void) const { return _model; }

void		ClapTrap::setName(std::string name) { _name = name; }
void		ClapTrap::setHitPoint(int hitPoint) { 
	if (hitPoint > getMaxHitPoint()) {
		std::cout << "| Warning | Hit-point can't exceed max hit-point! Health set to max" << std::endl;
		_hitPoint = getMaxHitPoint(); 
	}
	else
		_hitPoint = hitPoint; 
}
void		ClapTrap::setMaxHitPoint(int maxHitPoint) { _maxHitpoint = maxHitPoint; }
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
void		ClapTrap::setModel(std::string model) { _model = model; }

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
	
	if ((unsigned int)getHitPoint() + amount >= (unsigned int)getMaxHitPoint()) {
		std::cout  << getModel() << " " << getName() << " repaired " << (unsigned int)getHitPoint() + amount - 10 << " hitpoints, ";
		setHitPoint(getMaxHitPoint());
		std::cout << "current hitpoint is " << getHitPoint() << std::endl;
	}
	else {
		std::cout << getModel() << " " << getName() << " repaired " << amount << " hitpoints, ";
		setHitPoint((unsigned int)getHitPoint() + amount);
		std::cout << "current hitpoint is " << getHitPoint() << std::endl;
	}
}
