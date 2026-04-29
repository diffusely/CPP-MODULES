#include "MateriaSource.h"

MateriaSource::MateriaSource()
	: _inventory()
{
	std::cout << "MateriaSource object created with default constructor!\n";
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++) {
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i];
	}
	std::cout << "MateriaSource object copied!\n";
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "MateriaSource object destroyed!\n";
}

bool	MateriaSource::inLearnInventory(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return (1);
	}
	return (0);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m) {
		std::cout << "Cannot learn invalid materia\n";
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i]) {
			if (inLearnInventory(m))
				_inventory[i] = m->clone();
			else
				_inventory[i] = m;
			std::cout << "Materia " << _inventory[i]->getType() << " learned at index " << i << "\n";
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	std::cout << "Cannot create materia, " << type << " is invalid!\n";
	return (NULL);
}
