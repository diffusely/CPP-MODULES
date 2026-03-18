#pragma once

#include <iostream>
#include <string>

class Zombie
{
public:

	Zombie();
	Zombie(const std::string &name);
	~Zombie();

	void announce(void);
	const std::string& getName() const;
	void setName(const std::string& name);

private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
