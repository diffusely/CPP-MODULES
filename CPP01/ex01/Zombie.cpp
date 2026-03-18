#include "Zombie.h"

Zombie::Zombie()
	: _name("")
{}

Zombie::Zombie(const std::string& name)
	: _name(name)
{
	std::cout << "Zombie " << _name << " created!\n";
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed!\n";
}

void Zombie::announce(void)
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ...\n";
}

const std::string& Zombie::getName() const
{
	return _name;
}

void Zombie::setName(const std::string& name)
{
	_name = name;
}

