#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(Animal const& copy);
	virtual	~Animal();
	Animal&	operator=(const Animal& other);
	const std::string&	getType(void) const;
	void setType(std::string str);
	virtual void makeSound(void) const;

protected:
	std::string	_type;
};
