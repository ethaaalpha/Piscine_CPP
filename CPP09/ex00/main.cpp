#include "BitcoinExchange.hpp"

// faire la forme canonique

int main(int argc, char **argv)
{
	BitcoinExchange btc;

	if (argc != 2)
		return (std::cout << "Wrong numbers of args : ./btc <inputfile>", 1);
	else
		btc.doAnalyse(argv[1]);
	return (0);
}
