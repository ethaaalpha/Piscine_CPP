#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &parent)
{
	(*this) = parent;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &parent)
{
	(void) parent;
	//do something here;
	return (*this);
}

PmergeMe::~PmergeMe(void) {}