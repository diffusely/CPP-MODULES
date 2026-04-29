#pragma once

#include "AAnimal.h"
#include "Brain.h"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog& copy);
	~Dog();

	Dog& operator=(const Dog& other);
	Brain* getBrain() const;
	void makeSound() const;

private:
	Brain* brain;
};
