#pragma once
#include <iostream>
#include <deque>
#include <list>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <limits>

class PmergeMe
{
private:
	std::deque<int> _deque;
	std::list<int>	_list;

public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe& operator=(const PmergeMe &parent);
	PmergeMe(const PmergeMe &parent);

	void treatEntry(const char *items[], int len) const;
	void doSorts(const char *items[], int len);

	void				handleListSort(const char *item[], int len);
	std::list<int>		mergeTwoLists(std::list<int> a, std::list<int> b);
	std::list<int>		mergeList(std::list<int>);

	void				handleDequeSort(const char *item[], int len);
	std::deque<int>		mergeTwoDeque(std::deque<int> a, std::deque<int> b);
	std::deque<int>		mergeDeque(std::deque<int>);

	class SyntaxException : public std::exception {
		public:
			virtual const char * what() const throw () { return ("invalid character found !");}
	};

	class OverFlowException : public std::exception {
		public:
			virtual const char * what() const throw () { return ("too high number must be an integer !");}
	};
};
