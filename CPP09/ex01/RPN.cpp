#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& parent) { *this = parent; }

RPN& RPN::operator=(const RPN& parent)
{
	(void) parent;
	return (*this);
}

RPN::~RPN(void)
{
}

void	RPN::doCalculation(std::string n_list)
{
	try {
		checkStringSyntax(n_list);
	} catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}

void	RPN::checkStringSyntax(std::string str)
{
	unsigned int i = 0, pos = 0;

	if (str.find_first_not_of("0123456789 +-/*") != std::string::npos)
		throw (InvalidCharacterException());
	while (str.find(' ', i) != std::string::npos)
	{
		pos = str.find(' ', i);
		_stack.push(str.substr(i, pos));
		i = pos + 1;
	}
	std::cout << _stack.top() << std::endl;
	_stack.pop();
	std::cout << _stack.top() << std::endl;
	_stack.pop();
	std::cout << _stack.top() << std::endl;
	_stack.pop();
	std::cout << _stack.top() << std::endl;
	_stack.pop();
}
