#include "Harl.hpp"

int main(void)
{
	/* code */
	Harl h = Harl();
	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	return 0;
}
