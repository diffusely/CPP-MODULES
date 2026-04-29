#pragma once

#include "AMateria.h"
#include "ICharacter.h"

class ICharacter;

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& copy);
	~Cure();

	Cure& operator=(const Cure& other);
	AMateria* clone(void) const;
	void use(ICharacter& target);
};
