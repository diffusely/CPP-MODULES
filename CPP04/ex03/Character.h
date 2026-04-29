#pragma once

#include "ICharacter.h"

class Character : public ICharacter
{
public:
	Character(void);
	Character(std::string const &name);
	Character(const Character& copy);
	~Character();

	Character& operator=(const Character& other);
	const std::string& getName(void) const;
	void setName(std::string name);
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria* _inventory[4];

private:
	bool inInventory(AMateria* m);
};
