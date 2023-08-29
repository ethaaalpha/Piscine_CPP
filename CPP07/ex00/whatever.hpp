#pragma once

template <typename E>
void swap(E &a, E &b)
{
	E temp = a;
	a = b;
	b = temp;
	return ;
}

template <typename E>
E& min(E &a, E &b)
{
	if (a == b)
		return (b);
	else
		return (b > a ? a : b);
}

template <typename E>
E& max(E &a, E &b)
{
	if (a == b)
		return (b);
	else
		return (b < a ? a : b);
}
