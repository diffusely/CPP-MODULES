#pragma once

#include <iostream>
#include <string>
#include "ICharacter.h"

class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& copy);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& other);
	const std::string& getType(void) const;
	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string	_type;
};

