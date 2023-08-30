#include "Span.hpp"

int main(void)
{
	try {
		Span sp = Span(1);
		sp.addNumber(10);
		sp.addNumber(10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std ::endl;
	}
	
	try {
		Span sp = Span(1);
		sp.addNumber(1);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		Span sp = Span(8);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(10);
		sp.addNumber(17);
		sp.addNumber(30000);
		sp.addNumber(0);
		sp.addNumber(14);
		sp.addNumber(45000);
		sp.show();
		std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
	} catch (std::exception &e) {}

	try {
		Span sp = Span(8);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		sp.addNumber(40);
		sp.addNumber(50);
		sp.addNumber(60);
		sp.addNumber(71);
		sp.addNumber(72);
		sp.show();
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl << std::endl;
	} catch (std::exception &e) {}

	try {
		Span sp = Span(100000);
		sp.fillRandom();
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
	} catch (std::exception &e) {}

	try {
		Span sp = Span(8);
		std::vector<unsigned int> numbers(10, 1);
		sp.fillRange(numbers.begin(), numbers.end());
		sp.show();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		Span sp = Span(100);
		std::vector<unsigned int> numbers(10, 55);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(6);
		sp.fillRange(numbers.begin(), numbers.end());
		sp.show();
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
