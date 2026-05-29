#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

enum Protection {
	ON,
	OFF
};

class ScavTrap : public ClapTrap {
private:
	Protection	_protection;

public:
	ScavTrap(void);
	ScavTrap(std::string model, std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap(void);

	ScavTrap&	operator=(const ScavTrap& other);

	Protection	getProtection(void) const;
	
	void		setProtection(Protection protection);

	void		takeDamage(unsigned int amount);
	void		guardGate();
};

#endif