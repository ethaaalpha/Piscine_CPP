#include "Harl.hpp"

int main(void)
{
	Harl h = Harl();

	for (int i = 0; i < 3; i++)
	{
		h.complain("DEBUG");
		h.complain("INFO");
		h.complain("WARNING");
		h.complain("ERROR");
	}
	return 0;
}
