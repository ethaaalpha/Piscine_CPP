#pragma once
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain(void);
    Brain(const Brain &parent);
    Brain& operator=(const Brain &parent);
    ~Brain();
};

Brain::Brain(void)
{
    std::cout << 
}

Brain::Brain(const Brain &parent)
{

}



Brain::~Brain(void)
{
}
