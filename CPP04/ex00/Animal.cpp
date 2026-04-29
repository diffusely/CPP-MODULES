#include "Animal.h"

Animal::Animal()
	: _type("Unknown")
{
	std::cout << "Animal's default constructor " << _type << "\n";
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal's default constructor " << _type << "\n";
}

Animal::~Animal()
{
	std::cout << "Animal's destructor " << _type << "\n";
}

Animal::Animal(const Animal& copy)
{
	_type = copy._type;
	std::cout << "Animal's copy constructor " << _type << "\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal's copy assignment operator " << _type << "\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string& Animal::getType(void) const
{
	return (_type);
}

void Animal::setType(std::string str)
{
	_type = str;
}

void Animal::makeSound() const
{
	std::cout << "Undefined sound\n";
}
