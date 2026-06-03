#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " filled with power" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " filled with power" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copied from " << _name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
        std::string oldName = _name;

        ClapTrap::operator=(other);
        std::cout << "FragTrap " << oldName << " copied the features of " << _name;
		std::cout << ", it's old self has been erased." << std::endl;
    }
	
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been scrapped" << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (_hitPoint <= 0) {
		std::cout << "FragTrap " << _name << "has damaged a lot can't move it's arm..." << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " i don't wanna fight lets high fives!" << std::endl;
}