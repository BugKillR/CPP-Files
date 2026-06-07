#include "./MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0) {
	std::memset(_materials, 0, sizeof(_materials));
}

MateriaSource::MateriaSource(const MateriaSource& other) : _count(other._count) {
	std::memset(_materials, 0, sizeof(_materials));

	for (int i = 0; i < _count; i++)
		_materials[i] = other._materials[i]->clone();
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _count; i++)
		delete _materials[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _count; i++)
			delete _materials[i];

		_count = other._count;

		std::memset(_materials, 0, sizeof(_materials));

		for (int i = 0; i < _count; i++)
			_materials[i] = other._materials[i]->clone();

	}

	return *this;
}

void			MateriaSource::learnMateria(AMateria* mat) {
	if (mat == NULL || 4 <= _count) {
		delete mat;
		return;
	}

	_materials[_count++] = mat->clone();
	delete mat;
}

AMateria*		MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < _count; i++) {
		if (_materials[i]->getType() == type)
			return _materials[i]->clone();
	}

	return NULL;
}