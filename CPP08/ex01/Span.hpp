#pragma once
#include <exception>
#include <algorithm>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <vector>

class Span
{
private:
	unsigned int					_size;
	std::vector<unsigned int>		_tab;
	Span(void);

public:
	Span(const Span& parent);
	Span& operator=(const Span& parent);
	~Span(void);

	Span(unsigned int n);

	void addNumber(int value);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	void fillRange(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);

	//tools
	void show(void) const;
	void fillRandom(void);

	class SpanTooSmall : public std::exception
	{
	public:
		virtual const char* what() const throw() { return ("Span is too small to do operation !");}
	};
	
	class OutOfSize : public std::exception
	{
	public:
		virtual const char* what() const throw() { return ("Attempt to go out the size of the span !");}
	};
	
};
