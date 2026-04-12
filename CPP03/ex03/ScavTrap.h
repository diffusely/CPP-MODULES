#pragma once

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap
{
public:

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& copy);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap& other);
	void guardGate();
	void attack(const std::string& target);

};