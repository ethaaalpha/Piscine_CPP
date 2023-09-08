#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	RPN rp;
	if (argc != 2)
		return (std::cout << "Syntax error ./RPN 'rpn-numbers' !", 1);
	else
		rp.doCalculation(argv[1]);
	return (0);
}
