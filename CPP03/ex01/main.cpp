#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int	main(void) {
	ClapTrap	c1("ClapTrap", "Ersin");
	ScavTrap	s1("ScavTrap", "Atacan");
	

	c1.attack("Atacan");
	c1.takeDamage(3);
	c1.attack("Atacan");
	c1.beRepaired(4);
	c1.takeDamage(5);
	c1.beRepaired(3);
	c1.takeDamage(9);

	c1.attack("Atacan");
	c1.takeDamage(5);
	c1.beRepaired(7); 

	s1.attack("Ersin");
	s1.guardGate();
	s1.takeDamage(37);
	s1.takeDamage(37);
	s1.attack("Ersin");
	s1.beRepaired(25);
	s1.takeDamage(33);
	s1.beRepaired(12);
	s1.takeDamage(61);

	s1.attack("Ersin");
	s1.takeDamage(7);
	s1.beRepaired(7); 

	return 0;
}