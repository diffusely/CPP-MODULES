#pragma once

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria* m);
	AMateria* createMateria(const std::string& type);

private:
	AMateria* _inventory[4];
	bool inLearnInventory(AMateria* m);
};
