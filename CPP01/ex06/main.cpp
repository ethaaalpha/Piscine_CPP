#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl h = Harl();

	if (argc != 2)
		h.complain("UNKNOW");
	else
		h.complain(argv[1]);
	return 0;
}
