#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < (int)strlen(argv[i]); j++)
				std::cout << (char) toupper(argv[i][j]);
			if (i + 1 < argc)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}