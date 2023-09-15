#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	PmergeMe pm;
	if (argc < 2)
		return (std::cout << "Syntax error : ./PmergeMe numbers !" << std::endl, 1);
	if (argc < 3)
		return (std::cout << "Can't sort only one number !" << std::endl, 1);
	else
		pm.doSorts(argv + 1, argc - 1);
	return (0);
}