#include "BitcoinExchange.hpp"

int main(void)
{
	BitcoinExchange btc;

	btc.fillHistoricValues("data.csv");
	return (0);
}
