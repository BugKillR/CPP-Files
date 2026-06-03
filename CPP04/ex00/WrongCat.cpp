#include "./WrongCat.hpp"

WrongCat::WrongCat() { type = "wrong cat"; std::cout << "Const : Cat created, what a cute one!" << std::endl; }
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) { std::cout << "Copy  : Cat copied, what a cute one!" << std::endl; }
WrongCat::~WrongCat() { std::cout << "Dest  : Cat destroyed, I hope you haven't spent all your lives." << std::endl; }

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "Copy A: Cat adopted a new identity" << std::endl;
	return *this;
}

void		WrongCat::makeSound() const {
	std::cout << "* mrrrr...... *" << std::endl;
}