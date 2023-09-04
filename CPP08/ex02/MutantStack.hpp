#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	
	typedef typename std::stack<T>::container_type::iterator 				iterator;
	typedef typename std::stack<T>::container_type::const_iterator 			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator 		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator 	const_reverse_iterator;

	MutantStack(void);
	MutantStack(const MutantStack& parent) : std::stack<T>(parent) {}
	MutantStack& operator=(const MutantStack& parent)
	{
		std::stack<T>::operator=(parent);
		return (*this);
	}
	~MutantStack(void);

	iterator begin(void) { 
		return (std::stack<T>::c.begin()); 
	}

	const_iterator cbegin(void) const {
		return (std::stack<T>::c.begin());
	}

	iterator end(void) {
		return (std::stack<T>::c.end());
	}

	const_iterator cend(void) const {
		return (std::stack<T>::c.end());
	}

	reverse_iterator rbegin (void) {
		return (std::stack<T>::c.rbegin());
	}
	
	const_reverse_iterator crbegin (void) const {
		return (std::stack<T>::c.rbegin());
	}

	reverse_iterator rend (void) {
		return (std::stack<T>::c.rend());
	}
	
	const_reverse_iterator crend (void) const {
		return (std::stack<T>::c.rend());
	}

};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack(void) {}
