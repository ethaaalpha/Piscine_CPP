#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor !" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &parent)
{
	std::cout << "Brain parent constructor !" << std::endl;
	*this = parent;
}

Brain& Brain::operator=(const Brain &parent)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = parent.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor !" << std::endl;
}

void Brain::setIdea(std::string idea, unsigned int index)
{
	if (index > 99)
		return;
	ideas[index] = idea;
}

const std::string* Brain::getIdeas(void) const
{
	return (ideas);
}

void Brain::printIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i] != "")
			std::cout << i << " : " << ideas[i] << std::endl; 
	}
}
