#include "./Dog.hpp"

Dog::Dog() { 
	std::cout << "Const : Dog created, what a loyal friend!" << std::endl;
	type = "dog";
	brain = new Brain();
}
Dog::Dog(const Dog& other) : Animal(other) { std::cout << "Copy  : Dog copied, what a loyal friend!" << std::endl; }
Dog&	Dog::operator=(const Dog& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Copy A: Dog adopted a new identity" << std::endl;
	return *this;
}
Dog::~Dog() { 
	std::cout << "Dest  : Dog destroyed, goodbye old friend..." << std::endl;
	delete brain;
}

void	Dog::makeSound() const {
	std::cout << "* woof wof * " << std::endl;
}