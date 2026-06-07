#include "./MateriaSource.hpp"
#include "./Ice.hpp"
#include "./Cure.hpp"
#include "./Character.hpp"

int	main(void)
{

	std::cout << "\n------ Standard Part ------" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	std::cout << "-----  Advanced Test  -----" << std::endl;

	Character* c1 = new Character("kijo");
	Character* c2 = new Character("tsuki");

	MateriaSource* src1 = new MateriaSource();

	// Unknown materia
	tmp = src1->createMateria("cure");
	if (!tmp)
		std::cout << "createMateria failed as expected." << std::endl;

	// Learn 4 materias
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	// 5th should be ignored
	src1->learnMateria(new Ice());

	std::cout << "----- MateriaSource Copy Constructor -----" << std::endl;

	MateriaSource src2(*src1);

	tmp = src2.createMateria("ice");
	c1->equip(tmp);

	tmp = src2.createMateria("cure");
	c1->equip(tmp);

	std::cout << "copied and equiped some item on it" << std::endl;

	std::cout << "----- Use Test -----" << std::endl;

	c1->use(0, *c2);
	c1->use(1, *c2);

	std::cout << "----- Unequip Test -----" << std::endl;

	c1->unequip(0);

	std::cout << "nothing should happen" << std::endl;
	c1->use(0, *c2);

	std::cout << "----- Inventory Limit Test -----" << std::endl;

	c1->equip(src2.createMateria("ice"));
	c1->equip(src2.createMateria("cure"));
	c1->equip(src2.createMateria("ice"));
	c1->equip(src2.createMateria("cure")); // inventory already full

	std::cout << "already added 4 material last 2 is deleted" << std::endl;

	std::cout << "----- Character Copy Constructor -----" << std::endl;

	Character copy(*c1);

	copy.use(0, *c2);
	copy.use(1, *c2);
	copy.use(2, *c2);
	copy.use(3, *c2);

	std::cout << "----- Character Assignment Operator -----" << std::endl;

	Character assigned("assigned");

	assigned = *c1;

	assigned.use(0, *c2);
	assigned.use(1, *c2);
	assigned.use(2, *c2);
	assigned.use(3, *c2);

	delete c1;
	delete c2;
	delete src1;

	std::cout << "----------------------------\n" << std::endl;

	return 0;
}
