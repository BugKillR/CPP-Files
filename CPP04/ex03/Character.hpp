#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <cstring>
# include "./ICharacter.hpp"
# include "./AMateria.hpp"

// https://www.youtube.com/watch?v=_CgOLZMbILQ&list=RDOc4GkdgZ3jE&index=13

class Character : public ICharacter {
private:
	std::string	_name;
	AMateria*	_inventory[4];
	AMateria*	_collector[1000];
	int			_collectedCount;

public:
	Character();
	Character(std::string const& name);
	Character(const Character& other);
	virtual ~Character();

	Character&	operator=(const Character& other);

	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif