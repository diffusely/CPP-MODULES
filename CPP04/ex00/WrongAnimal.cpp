#include "WrongAnimal.h"

WrongAnimal::WrongAnimal()
	: _type("Unknown")
{
	std::cout << "WrongAnimal's default constructor called with type " << _type << "\n";
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal's default constructor called with type " << _type << "\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's destructor called with type " << _type << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	_type = copy._type;
	std::cout << "WrongAnimal's copy constructor called with type " << _type << "\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "WrongAnimal's copy assignment operator called with type " << _type << "\n";
	return (*this);
}

const std::string&	WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::setType(std::string str)
{
	_type = str;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Undefined sound\n";
}
