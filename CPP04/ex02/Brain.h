#pragma once 

#include <iostream>
#include <string>

class Brain
{
public:
	Brain(void);
	Brain(const Brain& copy);
	~Brain();

	Brain& operator=(const Brain& other);
	const std::string& getIdea(int index) const;
	void setIdea(std::string idea, int index);

private:
	std::string	idea[100];
};
