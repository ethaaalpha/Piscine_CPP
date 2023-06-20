#include <iostream>
#include <iomanip>


int ft_trim(std::string item)
{
	size_t start = item.find_first_not_of(" ");
	size_t end = item.find_last_not_of(" ");
	if (start == std::string::npos)
		return (1);
	else
	{
		item = item.substr(end - start, start);
		return (0);
	}
}

std::string getLimitedInfo(std::string item)
{
	if (item.size() > 10)
	{
		item.replace(9, 1, ".");
		item.resize(10);
	}
	return (item);
}


