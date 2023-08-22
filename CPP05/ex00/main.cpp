#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat alfred_toohigh = Bureaucrat("Alfred", 0);
		std::cout << alfred_toohigh;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Bureaucrat alfred_toolow = Bureaucrat("Alfred", 151);
		std::cout << alfred_toolow;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Bureaucrat alfred_rankup = Bureaucrat("Alfred", 4);
		std::cout << alfred_rankup;
		while (1)
			alfred_rankup.rankUp();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Bureaucrat alfred_rankdown = Bureaucrat("Alfred", 145);
		std::cout << alfred_rankdown;
		while (1)
			alfred_rankdown.rankDown();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
