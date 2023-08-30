#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <exception>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw () {
			return ("Value not found in T");
		}
};

template <typename T>
typename T::iterator easyfind(T &item, int n)
{
	typename T::iterator it = std::find(item.begin(), item.end(), n);

	if (it == item.end())
		throw (NotFoundException());
	else
		return (it);
}