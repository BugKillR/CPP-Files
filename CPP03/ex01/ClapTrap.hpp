#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

enum Status {
	ALIVE,
	DEAD
};

class ClapTrap {
private:
	std::string	_model;

protected:
	std::string	_name;
	int			_hitPoint;
	int			_maxHitpoint;
	int			_energyPoint;
	int			_attackDamage;
	Status		_status;

	Status		getStatus(void) const;
	std::string	getModel(void) const;

	void		setName(std::string name);
	void		setHitPoint(int hitPoint);
	void		setMaxHitPoint(int maxHitPoint);
	void		setEnergyPoint(int energyPoint);
	void		setStatus(Status status);
	void		setModel(std::string model);

public:
	ClapTrap();
	ClapTrap(std::string model, std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	std::string	getName(void) const;
	int			getHitPoint(void) const;
	int			getMaxHitPoint(void) const;
	int			getEnergyPoint(void) const;
	int			getAttackDamage(void) const;

	void		setAttackDamage(int attackDamage);


	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif