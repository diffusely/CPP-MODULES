#include "Dog.h"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog's default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called\n";
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Dog's copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog's copy assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}