#pragma once

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& copy);
	~Dog();

	Dog& operator=(Dog const& other);
	Brain* getBrain() const;
	void makeSound() const;

private:
	Brain*	brain;
};
