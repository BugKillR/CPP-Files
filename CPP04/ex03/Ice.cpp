#include "./Ice.hpp"

Ice::Ice() : AMateria("ice") { }
Ice::Ice(std::string const& type) : AMateria(type) { }
Ice::Ice(const Ice& other) : AMateria(other) { }
Ice::~Ice() { }

Ice&    Ice::operator=(const Ice& other) {
    if (this != &other)
        AMateria::operator=(other);
    
    return *this;
}

Ice*    Ice::clone() const { return new Ice(*this); }
void    Ice::use(ICharacter& target) { 
    std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}