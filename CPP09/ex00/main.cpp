#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange btc;

	if (argc != 2)
		return (std::cout << "Wrong numbers of args : ./btc <inputfile>" << std::endl, 1);
	else
		btc.doAnalyse(argv[1]);
	return (0);
}
