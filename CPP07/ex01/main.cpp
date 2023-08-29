#include <iostream>
#include "whatever.hpp"

int main( void ) 
{
	int int_tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	showTab(int_tab, 10);
	iter(int_tab, 10, exampleFunction<int>);
	showTab(int_tab, 10);
	
	std::cout << std::endl;

	float float_tab[10] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f};
	showTab(float_tab, 10);
	iter(float_tab, 10, exampleFunction<float>);
	showTab(float_tab, 10);

	std::cout << std::endl;

	double double_tab[10] = {1.0005, 1.0005, 2.0005, 3.0005, 4.0005, 5.0005, 6.0005, 7.0005, 8.0005, 9.0005};
	showTab(double_tab, 10);
	iter(double_tab, 10, exampleFunction<double>);
	showTab(double_tab, 10);

	std::cout << std::endl;

	char char_tab[5] = "abcd";
	showTab(char_tab, 4);
	iter(char_tab, 5, exampleFunction<char>);
	showTab(char_tab, 4);

	return (0);
}