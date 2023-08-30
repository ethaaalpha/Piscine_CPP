#pragma once
#include <algorithm>
#include <iostream>

class Span
{
private:
	/* data */
public:
	Span(void);
	Span(const Span& parent);
	Span& operator=(const Span& parent);
	~Span(void);
};

Span::Span(void)
{
}

Span::Span(const Span& parent)
{
	(*this) = parent;
}

Span& Span::operator=(const Span& parent)
{
	
}

Span::~Span(void)
{
}
