#include "Array.hpp"

int main(void)
{
	Array<char> char_array(10);
	for (int i = 0; i < 10; i++)
		char_array[i] = 'a' + i;

	std::cout << "char_array :" << std::endl;
	std::cout << char_array << std::endl << std::endl;

	Array<char> char_array_copy = char_array;
	std::cout << "char_array_copy :" << std::endl;
	std::cout << char_array_copy << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
		char_array_copy[i] = 'k' + i;

	std::cout << "char_array :" << std::endl;
	std::cout << char_array << std::endl << std::endl;

	std::cout << "char_array_copy :" << std::endl;
	std::cout << char_array_copy << std::endl << std::endl;

	try {
		char_array[10] = 'a';
	} catch (std::exception &e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}

	return 0;
}
