#pragma once
#include <cstddef>

template <typename E, typename F>
void iter(E *tab, size_t len, F function)
{
	for (size_t i = 0; i < len; i++)
		function(tab[i]);
}

template <typename E>
void exampleFunction(E &value)
{
	value += 1;
}

template <typename E>
void showTab(E *tab, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (i + 1 < len)
			std::cout << tab[i] << ", ";
		else
			std::cout << tab[i] << std::endl;
	}
}