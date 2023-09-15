#pragma once
#include <iostream>
#include <deque>
#include <list>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>

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

	// void 				handleDequeSort(void);

	class SyntaxException : public std::exception {
		public:
			virtual const char * what() const throw () { return ("invalid character found !");}
	};
};
