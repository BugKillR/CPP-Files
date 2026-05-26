#include <iostream>

void	megaphone(char *str)
{
	for (int i = 0; str[i]; i++)
		std::cout << (char)(std::toupper(str[i]));
}

int main(int ac, char *av[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < ac; i++)
			megaphone(av[i]);
	std::cout << std::endl;
	return (0);
}
