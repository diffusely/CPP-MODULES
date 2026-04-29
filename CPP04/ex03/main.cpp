#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>

int	main()
{
	std::cout << "========== SUBJECT TEST ==========\n" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n========== DEEP COPY TEST ==========\n" << std::endl;
	{
		Character a("Alice");

		AMateria *m1 = new Ice();
		AMateria *m2 = new Cure();

		a.equip(m1);
		a.equip(m2);

		Character b = a;

		Character target("Target");

		a.use(0, target);
		b.use(0, target);

		b.use(1, target);

		std::cout << "\nModify copy only:\n";
		AMateria *extra = new Ice();
		b.equip(extra);

		a.use(1, target);
	}

	std::cout << "\n========== EQUIP LIMIT TEST ==========\n" << std::endl;
	{
		Character c("Bob");

		AMateria *m[5];

		m[0] = new Ice();
		m[1] = new Cure();
		m[2] = new Ice();
		m[3] = new Cure();
		m[4] = new Ice();

		for (int i = 0; i < 4; i++)
			c.equip(m[i]);

		delete m[4];

		c.use(0, c);
		c.use(1, c);
		c.use(2, c);
		c.use(3, c);
		c.use(4, c);
	}

	std::cout << "\n========== UNEQUIP TEST ==========\n" << std::endl;
	{
		Character c("Bob");

		AMateria *m1 = new Ice();
		c.equip(m1);

		c.unequip(0);

		delete m1;

		Character target("Target");
		c.use(0, target);
	}

	std::cout << "\n========== FINISHED ==========\n";
	return (0);
}