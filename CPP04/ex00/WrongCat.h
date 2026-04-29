#pragma once

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& wrongCat);
	~WrongCat();

	WrongCat& operator=(const WrongCat& other);
	void makeSound(void) const;

};