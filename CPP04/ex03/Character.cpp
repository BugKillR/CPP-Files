#include "./Character.hpp"

Character::Character() : _name("player"), _collectedCount(0) {
	std::memset(_collector, 0, sizeof(_collector));
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(std::string const& name) : _name(name), _collectedCount(0) {
	std::memset(_collector, 0, sizeof(_collector));
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(const Character& other) : _name(other._name), _collectedCount(0) {
	std::memset(_collector, 0, sizeof(_collector));
	std::memset(_inventory, 0, sizeof(_inventory));

	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}

	for (int i = 0; i < _collectedCount; i++)
		delete _collector[i];
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;

		for (int i = 0; i < 4; i++) {
			if (_inventory[i] != NULL)
				delete _inventory[i];
		}

		std::memset(_inventory, 0, sizeof(_inventory));

		for (int i = 0; i < 4; i++) {
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
		}


		for (int i = 0; i < _collectedCount; i++)
			delete _collector[i];
		
		std::memset(_collector, 0, sizeof(_collector));
		_collectedCount = 0;
	}

	return *this;
}

std::string const&	Character::getName() const { return _name; }

void				Character::equip(AMateria* m) {
	if (!m)
		return;
	
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
	
	delete m;
}

void				Character::unequip(int idx) {
	if (_inventory[idx] != NULL) {
		_collector[_collectedCount] = _inventory[idx];
		_collectedCount++;
		_inventory[idx] = NULL;
	}
}

void				Character::use(int idx, ICharacter& target) {
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
}