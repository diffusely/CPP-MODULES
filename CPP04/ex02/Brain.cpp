#include "Brain.h"

Brain::Brain(void)
{
	std::cout << "Brain's default constructor called" << "\n";
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called" << "\n";
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain's copy constructor called" << "\n";
	for (int i = 0; i < 100; ++i)
		this->idea[i] = copy.idea[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain's copy assignment operator called" << "\n";
	if (this != &other)
		for (int i = 0; i < 100; ++i)
			this->idea[i] = other.idea[i];
	return (*this);
}

const std::string&	Brain::getIdea(int index) const
{
	return (*(this->idea + index));
}

void	Brain::setIdea(std::string idea, int index)
{
	this->idea[index] = idea;
}
