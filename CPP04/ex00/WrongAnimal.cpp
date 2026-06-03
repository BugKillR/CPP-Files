#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong animal") { std::cout << "Const : Animal created, what type of animal is this???" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) { std::cout << "Copy  : Animal copied, what type of animal is this???" << std::endl; }
WrongAnimal::~WrongAnimal() { std::cout << "Dest  : Animal destroyed, R.I.P..." << std::endl; }

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		type = other.type;
	std::cout << "Copy A: Animal adopted a new identity" << std::endl;	
	return *this;
}

std::string		WrongAnimal::getType(void) const { return type; }

void	WrongAnimal::makeSound() const {
	std::cout << "* animal noises *" << std::endl;
}