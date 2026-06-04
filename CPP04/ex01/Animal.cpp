#include "./Animal.hpp"

Animal::Animal() : type("animal") { std::cout << "Const : Animal created, what type of animal is this???" << std::endl; }
Animal::Animal(const Animal& other) : type(other.type) { std::cout << "Copy  : Animal copied, what type of animal is this???" << std::endl; }
Animal&	Animal::operator=(const Animal& other) {
	if (this != &other)
		type = other.type;
	std::cout << "Copy A: Animal adopted a new identity" << std::endl;	
	return *this;
}
Animal::~Animal() { std::cout << "Dest  : Animal destroyed, R.I.P..." << std::endl; }

std::string	Animal::getType(void) const { return type; }
void		Animal::setType(std::string _type) { type = _type; }

void	Animal::makeSound() const {
	std::cout << "* animal noises *" << std::endl;
}