#pragma once

#include "Weapon.h"

#include <iostream>
#include <string>

class HumanB
{
public:

	HumanB(const std::string& name);
	~HumanB();

	void setWeapon(Weapon& type);
	void attack() const;

private:
	std::string _name;
	Weapon* _weapon;
};
