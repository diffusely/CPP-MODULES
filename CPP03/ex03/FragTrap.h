#pragma once

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& copy);
	~FragTrap();

	FragTrap& operator=(const FragTrap& other);
	void highFivesGuys();
};
