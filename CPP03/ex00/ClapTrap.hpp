#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

enum Status {
	ALIVE,
	DEAD
};

class ClapTrap {
private:
	std::string	_name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;
	Status		_status;

	void		setStatus(Status status);

public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	std::string	getName(void) const;
	int			getHitPoint(void) const;
	int			getEnergyPoint(void) const;
	int			getAttackDamage(void) const;
	Status		getStatus(void) const;

	void		setName(std::string name);
	void		setHitPoint(int hitPoint);
	void		setEnergyPoint(int energyPoint);
	void		setAttackDamage(int attackDamage);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif