#pragma once

#include "Weapon.h"

#include <iostream>
#include <string>

class HumanA
{
public:

	HumanA(const std::string& name, Weapon& type);
	~HumanA();

	void setWeapon(const Weapon& type);
	void attack() const;

private:
	std::string _name;
	Weapon& _weapon;
};
