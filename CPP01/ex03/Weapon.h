#pragma once

#include <string>

class Weapon
{
public:

	Weapon(const std::string& type);
	~Weapon();
	const std::string& getType() const;
	void setType(const std::string& str);

private:
	std::string _name;
};