#include "Character.h"

Character::Character()
	: _name("Default")
	, _inventory()
{
	std::cout << "Character object created with default constructor!\n";
}

Character::Character(const std::string& name): _name(name), _inventory()
{
	std::cout << "Character object " << _name << " created!\n";
}

Character::Character(const Character& copy)
{
	_name = copy._name;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
	}
	std::cout << "Character object copied!\n";
}

Character &Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Character object destroyed!\n";
}

const std::string& Character::getName(void) const
{
	return (_name);
}

void Character::setName(std::string name)
{
	_name = name;
}

bool Character::inInventory(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m)
			return (1);
	}
	return (0);
}

void Character::equip(AMateria* m)
{
	if (!m) {
		std::cout << "Cannot equip invalid materia\n";
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i])
		{
			if (inInventory(m))
				_inventory[i] = m->clone();
			else
				_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped to " << _name << "'s inventory at index " << i << "\n";
			return ;
		}
	}
	std::cout << "Cannot equip materia, " << _name << "'s inventory is full!\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
		std::cout << "Materia doesn't exist" << "\n";
	else {
		std::cout << "Unequipped " << _inventory[idx]->getType() << " from inventory\n";
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
		std::cout << "Materia doesn't exist\n";
	else {
		std::cout << "In index " << idx << " ";
		_inventory[idx]->use(target);
	}
}
