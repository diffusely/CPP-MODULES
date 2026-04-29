#include "Dog.h"

Dog::Dog()
	: AAnimal("Dog")
{
	std::cout << "Dog's default constructor called\n";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called\n";
	delete brain;
}

Dog::Dog(const Dog& copy)
	: AAnimal(copy)
{
	std::cout << "Dog's copy constructor called\n";
	brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog's copy assignment operator called\n";
	if (this != &other) {
		_type = other._type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Brain* Dog::getBrain() const
{
	return (brain);
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}
