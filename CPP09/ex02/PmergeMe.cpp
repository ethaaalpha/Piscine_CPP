#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &parent)
{
	(*this) = parent;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &parent)
{
	_deque = parent._deque;
	_list = parent._list;

	return (*this);
}

PmergeMe::~PmergeMe(void) {}

void printTab(const char **tab, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << tab[i];
		if (i + 1 < len)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void printDeque(std::deque<int> l)
{
	for (std::deque<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != l.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::doSorts(const char *items[], int len)
{
	std::clock_t startList, endList, startDeque, endDeque;
	double		valueList, valueDeque;

	try {
		treatEntry(items, len);

		startList = std::clock();
		handleListSort(items, len);
		endList = std::clock();
		valueList = (double)(endList - startList) / CLOCKS_PER_SEC * 1000;
	
		startDeque = std::clock();
		handleDequeSort(items, len);
		endDeque = std::clock();
		valueDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC * 1000;

		std::cout << "Before: ";
		printTab(items, len);
		std::cout << "After: ";
		printDeque(_deque);
		std::cout << "Time to process a range of " << len << " elements with std::list : " << std::setprecision(6) << valueList << " ms" << std::endl;
		std::cout << "Time to process a range of " << len << " elements with std::deque : " << std::setprecision(6) << valueDeque << " ms" << std::endl;
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
		if (std::strlen(item[i]) > 10 || std::atol(item[i]) > std::numeric_limits<int>::max())
			throw (OverFlowException());
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

void PmergeMe::handleDequeSort(const char *item[], int len)
{
	for (int i = 0; i < len; i++)
		_deque.push_back(std::atoi(item[i]));
	_deque = mergeDeque(_deque);
}

std::deque<int> PmergeMe::mergeTwoDeque(std::deque<int> a, std::deque<int> b)
{
	std::deque<int> 			result;
	std::deque<int>::iterator	i, j;

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
		i = std::min_element(a.begin(), a.end());
		j = std::min_element(b.begin(), b.end());
		if (*i > *j)
		{
			result.push_back(*j);
			b.erase(j);
		}
		else
		{
			result.push_back(*i);
			a.erase(i);
		}		
	}
	return (result);
}

std::deque<int> PmergeMe::mergeDeque(std::deque<int> deque)
{
	std::deque<int> 	left, right;
	int				size;

	if (deque.size() == 1)
		return (deque);
	size = deque.size();
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			left.push_front(deque.front());
		else
			right.push_front(deque.front());
		deque.pop_front();
	}
	left = mergeDeque(left);
	right = mergeDeque(right);
	return (mergeTwoDeque(left, right));
}