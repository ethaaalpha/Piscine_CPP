#pragma once
#include <iostream>
#include <deque>
#include <list>
#include <exception>
#include <cstdlib>

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

	void handleListSort(const char *item[], int len);
	void mergeList(void);

	// void handleDequeSort(void);

	class SyntaxException : public std::exception {
		public:
			virtual const char * what() const throw () { return ("invalid character found !");}
	};
};
