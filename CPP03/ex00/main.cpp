#include "./ClapTrap.hpp"

int	main(void) {
	ClapTrap	c1;

	c1.setName("Ersin");

	c1.attack("Doruk");
	c1.takeDamage(3);
	c1.setAttackDamage(5);
	c1.attack("Doruk");
	c1.beRepaired(4);
	c1.takeDamage(5);
	c1.beRepaired(3);
	std::cout << c1.getName() << "'s current health: " << c1.getHitPoint() << std::endl;
	c1.takeDamage(9);

	c1.attack("Kemal");
	c1.takeDamage(5);
	c1.beRepaired(7); 

	return 0;
}