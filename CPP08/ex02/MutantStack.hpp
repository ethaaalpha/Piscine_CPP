#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public: 
	MutantStack(void);
	MutantStack(const MutantStack& parent) : std::stack<T>(parent) {}
	MutantStack& operator=(const MutantStack& parent)
	{
		std::stack<T>::operator=(parent);
		return (*this);
	}
	~MutantStack(void);

};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack(void) {}
