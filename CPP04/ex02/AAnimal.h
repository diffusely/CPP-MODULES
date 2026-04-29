#pragma once

#include <iostream>
#include <string>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal& copy);
	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal& other);
	const std::string& getType() const;
	void setType(std::string str);
	virtual void makeSound() const = 0;

protected:
	std::string	_type;
};


