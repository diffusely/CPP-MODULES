#include "Animal.h"

Animal::Animal(void): _type("Unknown")
{
	std::cout << "Animal's default constructor called with type " << _type << "\n";
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal's default constructor called with type " << _type << "\n";
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called with type " << _type << "\n";
}

Animal::Animal(const Animal& copy)
{
	_type = copy._type;
	std::cout << "Animal's copy constructor called with type " << _type << "\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Animal's copy assignment operator called with type " << _type << "\n";
	return (*this);
}

const std::string&	Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string str)
{
	_type = str;
}

void	Animal::makeSound(void) const
{
	std::cout << "Undefined sound" << "\n";
}
