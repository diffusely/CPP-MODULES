#pragma once

#include "AMateria.h"
#include "ICharacter.h"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice& copy);
	~Ice();

	Ice& operator=(const Ice& other);
	AMateria* clone() const;
	void use(ICharacter& target);
};
