#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap	*c1 = new ClapTrap("Ali");
	ClapTrap	*c2 = new ClapTrap(*c1);
	ClapTrap	*c3 = new ClapTrap("Doruk");

	*c3 = *c2;

	delete c1;
	delete c2;
	delete c3;

	ClapTrap	c4("Kayra");
	c4.attack("Ege");
	c4.takeDamage(5);
	c4.beRepaired(2);
	c4.takeDamage(8);
	c4.attack("Ege");

	return 0;
}