#include "./Zombie.hpp"

Zombie::Zombie() : _name("") { }

Zombie::Zombie(std::string name) { _name = name; }

Zombie::~Zombie() {
	std::cout << getName() << ": Grrr... Time to return to the dirt..." << std::endl;
}

std::string	Zombie::getName(void) const { return _name; }

void		Zombie::setName(std::string name) { _name = name; }     

void    Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
