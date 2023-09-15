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

void PmergeMe::doSorts(const char *items[], int len)
{
	try {
		treatEntry(items, len);
		handleListSort(items, len);
	} catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}

void PmergeMe::treatEntry(const char *item[], int len) const
{
	int i = 0;

	while (i < len)
	{
		if (std::string(item[i]).find_first_not_of("0123456789") != std::string::npos)
			throw (SyntaxException());
		i++;
	}
}

void PmergeMe::handleListSort(const char *item[], int len)
{
	for (int i = 0; i < len; i++)
		_list.push_back(std::atoi(item[i]));
	mergeList();
}

void PmergeMe::mergeList()
{
	
}