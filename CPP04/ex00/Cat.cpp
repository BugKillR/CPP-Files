#include "./Cat.hpp"

Cat::Cat() { type = "cat"; std::cout << "Const : Cat created, what a cute one!" << std::endl; }
Cat::Cat(const Cat& other) : Animal(other) { std::cout << "Copy  : Cat copied, what a cute one!" << std::endl; }
Cat&	Cat::operator=(const Cat& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Copy A: Cat adopted a new identity" << std::endl;
	return *this;
}

Cat::~Cat() { std::cout << "Dest  : Cat destroyed, I hope you haven't spent all your lives." << std::endl; }

void	Cat::makeSound() const {
	std::cout << "* mrrrr...... *" << std::endl;
}