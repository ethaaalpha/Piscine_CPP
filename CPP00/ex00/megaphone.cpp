#include <iostream>

void ft_trim(std::string item, char *dest)
{
	size_t start = item.find_first_not_of(" ");
	size_t end = item.find_last_not_of(" ");
	if (start == std::string::npos)
		dest[0] = '\0';
	else
	{
		item.copy(dest, end - start + 1, start);
		dest[end - start + 1] = '\0';
	}
}

int main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		while (i < argc)
		{
			ft_trim(argv[i], argv[i]);
			i++;
		}
		i = 1;
		while (i < argc)
		{
			int	j = 0;
			ft_trim(argv[i], argv[i]);
			while (argv[i][j])
			{
				std::cout << (char) toupper(argv[i][j]);
				j++;
			}
			if (argv[i][0] != '\0' && argv[i + 1] && argv[i + 1][0])
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}