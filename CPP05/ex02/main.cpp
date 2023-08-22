#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat agent = Bureaucrat("Christine", 150);
	std::cout << agent << std::endl;

	try {
		PresidentialPardonForm president =  PresidentialPardonForm("alfred");
		president.execute(agent);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << std::endl;

	return 0;
}
