#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& parent) { *this = parent; }

RPN& RPN::operator=(const RPN& parent)
{
	_stack = parent._stack;
	return (*this);
}

RPN::~RPN(void) {}

void	RPN::doCalculation(std::string n_list)
{
	try {
		checkStringSyntax(n_list);
		doRPN();
	} catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}

void	RPN::checkEachItems(std::string str)
{
	if (str.find_first_of("+-/*") != std::string::npos && str.length() != 1)
		throw (InvalidCharacterException());
	if (str.length() > 2 || std::atoi(str.c_str()) > 10)
		throw (HighNumberException());
}

void	RPN::checkStringSyntax(std::string str)
{
	unsigned int i = 0, pos = 0;

	if (str.find_first_not_of("0123456789 +-/*") != std::string::npos)
		throw (InvalidCharacterException());
	while (str.find(' ', i) != std::string::npos)
	{
		pos = str.find(' ', i);
		checkEachItems(str.substr(i, pos - i));
		_stack.push(str.substr(i, pos - i));
		i = pos + 1;
	}
	checkEachItems(str.substr(i, pos - str.size()));
	_stack.push(str.substr(i, pos - str.size()));
	
	std::stack<std::string> temp;
	while (_stack.size() > 0)
	{
		temp.push(_stack.top());
		_stack.pop();
	}
	_stack = temp;
}

int RPN::isNumber(std::string str)
{
	if (str.find_first_not_of("+-/*") != std::string::npos)
		return (1);
	return (0);
}

std::string RPN::itos(int value)
{
	std::stringstream ss;

	ss << value;
	return (ss.str());
}

int		RPN::doOperation(int left, int right, std::string sign)
{
	if (sign == "-") {
		return (left - right);
	} else if (sign == "+") {
		return (left + right);
	} else if (sign == "*") {
		return (left * right);
	} else {
		if (right == 0)
			throw (IllegalActionException());
		return (left / right);
	}
}

void	RPN::doRPN(void)
{
	std::stack<std::string> memory;
	int						right;
	int						left;

	if (_stack.size() < 3)
		throw (InvalidCalculationSyntaxeException());
	while (_stack.size() > 0)
	{
		if (!isNumber(_stack.top()) && memory.size() < 2)
			throw (InvalidCalculationSyntaxeException());
		else if (isNumber(_stack.top()))
		{
			memory.push(_stack.top());
			_stack.pop();
		}
		else if (!isNumber(_stack.top()))
		{
			right = std::atoi(memory.top().c_str());
			memory.pop();
			left = std::atoi(memory.top().c_str());
			memory.pop();
			memory.push(itos(doOperation(left, right, _stack.top())));
			_stack.pop();
		}
	}
	if (memory.size() != 1)
		throw (InvalidCalculationSyntaxeException());
	std::cout << std::atoi(memory.top().c_str()) << std::endl;
}