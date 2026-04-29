#pragma once

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& copy);
	~Dog();

	Dog& operator=(const Dog& other);
	void makeSound() const;
};
