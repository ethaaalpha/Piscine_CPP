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
		item.replace(10, 1, ".");
	return (item);
}

std::string getEntry(std::string entry_name)
{
	std::string input = "\0";

	std::cout << "Please, enter the " << entry_name << " !" << std::endl;
	getline(std::cin, input);
	while (ft_trim(input))
	{
		std::cout << "Error, the " << entry_name << " can't be empty (or filled of space) !" << std::endl;
		getline(std::cin, input);
	}
	return (input);
}
