#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <cstring>
# include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
AMateria*	_materials[4];
int			_count;

public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    virtual ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& other);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const& type);

};

#endif