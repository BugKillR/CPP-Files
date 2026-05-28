#include "./Zombie.hpp"

int	main(void) {
	
	Zombie	*z1 = newZombie("Heapster");

	randomChump("Stacky");
	z1->announce();

	delete z1;

	return (0);
}
