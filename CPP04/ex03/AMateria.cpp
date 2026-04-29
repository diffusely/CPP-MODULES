#include "AMateria.h"

AMateria::AMateria()
	: _type("Unidentified")
{}

AMateria::AMateria(const std::string& type): _type(type)
{
	std::cout << "AMatreia object created!\n";
}

AMateria::AMateria(const AMateria& copy)
{
	_type = copy._type;
	std::cout << "AMatreia object copied!\n";
}

AMateria::~AMateria()
{
	std::cout << "AMatreia object destroyed!\n";
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "AMatreia copy assignment operator called!\n";
	return (*this);
}

const std::string&	AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* " << target.getName() << " has undefined materia *\n";
}
