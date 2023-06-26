#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of str : " << &str << std::endl;
	std::cout << "Address of ptr : " << stringPTR << std::endl;
	std::cout << "Address of ref : " << &stringREF << std::endl;

	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value of ptr : " << *stringPTR << std::endl;
	std::cout << "Value of ref : " << stringREF << std::endl;
	return 0;
}
