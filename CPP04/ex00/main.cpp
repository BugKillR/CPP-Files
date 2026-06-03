#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"

#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"

int	main(void)
{

	std::cout << "\n------ Standard Part ------" << std::endl;

	Animal	*animals[4];

	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = NULL;

	for (size_t i = 0; animals[i]; i++) {
		std::cout << "Type  : " << animals[i]->getType() << std::endl;
		std::cout << "Sound : ";
		animals[i]->makeSound();
	}

	for (size_t i = 0; animals[i]; i++) {
		delete animals[i];
	}
	
	std::cout << "------  Broken Part  ------" << std::endl;

	WrongAnimal	*broken[3];

	broken[0] = new WrongAnimal();
	broken[1] = new WrongCat();
	broken[2] = NULL;

	for (size_t i = 0; broken[i]; i++) {
		std::cout << "Type  : " << broken[i]->getType() << std::endl;
		std::cout << "Sound : ";
		broken[i]->makeSound();
	}

	for (size_t i = 0; broken[i]; i++) {
		delete broken[i];
	}

	std::cout << "---------------------------\n" << std::endl;

	return 0;
}
