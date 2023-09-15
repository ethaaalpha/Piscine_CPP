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

void print(std::deque<int> l)
{
	for (std::deque<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
// Time to process a range of 5 elements with std::[..] : 0.00031 us
void PmergeMe::doSorts(const char *items[], int len)
{
	std::clock_t start, end;
	double		value;

	try {
		treatEntry(items, len);
		start = std::clock();
		handleListSort(items, len);
		end = std::clock();
		value = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process a range of " << len << " elements with std::list : " << std::setprecision(6) << value << " us" << std::endl;
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
	_list = mergeList(_list);
}

std::list<int> PmergeMe::mergeTwoLists(std::list<int> a, std::list<int> b)
{
	std::list<int> 	result;
	int				i, j;

	while (a.size() + b.size() != 0)
	{
		if (a.size() == 0 || b.size() == 0)
		{
			if (a.size() == 0)
				std::copy(b.begin(), b.end(), std::back_inserter(result));
			else if (b.size() == 0)
				std::copy(a.begin(), a.end(), std::back_inserter(result));
			break;
		}
		i = *std::min_element(a.begin(), a.end());
		j = *std::min_element(b.begin(), b.end());
		if (i > j)
		{
			result.push_back(j);
			b.remove(j);
		}
		else
		{
			result.push_back(i);
			a.remove(i);
		}		
	}
	return (result);
}

std::list<int> PmergeMe::mergeList(std::list<int> list)
{
	std::list<int> 	left, right;
	int				size;

	if (list.size() == 1)
		return (list);
	size = list.size();
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			left.push_front(list.front());
		else
			right.push_front(list.front());
		list.pop_front();
	}
	left = mergeList(left);
	right = mergeList(right);
	return (mergeTwoLists(left, right));
}