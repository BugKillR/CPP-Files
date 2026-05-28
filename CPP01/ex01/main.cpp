#include "./Zombie.hpp"

int	main(void)
{
	int		count = 5;

	Zombie	*horde = zombieHorde(count, "Null");

	for (int i = 0; i < count; i++)
	{
		std::cout << "Index |" << i << "| ";
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}