#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(int amount);
	void beRepaired(int amount);

private:
	std::string _name;
	int _hitPoint;
	int _energy;
	int _damage;
};
