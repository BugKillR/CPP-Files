#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"

int	main(void)
{

	std::cout << "\n------ Standard Part ------" << std::endl;

	Animal	*animals[5];

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
	animals[4] = NULL;

	for (size_t i = 0; animals[i]; i++) {
		std::cout << "Type  : " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	for (size_t i = 0; animals[i]; i++) {
		delete animals[i];
	}
	
	std::cout << "---------------------------\n" << std::endl;

	return 0;
}
