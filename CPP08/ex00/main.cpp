#include "easyfind.hpp"

int main( void ) 
{
	std::vector<int> vector_int(100);

	for (unsigned long i = 0; i < vector_int.size(); i++)
		vector_int.at(i) = i;

	std::cout << *easyfind(vector_int, 9) << std::endl;
	std::cout << *easyfind(vector_int, 18) << std::endl;
	std::cout << *easyfind(vector_int, 27) << std::endl;

	try {
		std::cout << *easyfind(vector_int, 100) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}