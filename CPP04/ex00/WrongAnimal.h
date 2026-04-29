#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& copy);
	virtual	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& other);
	const std::string& getType() const;
	void setType(std::string str);
	void makeSound() const;

protected:
	std::string	_type;
};