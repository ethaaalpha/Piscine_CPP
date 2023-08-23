#include "Intern.hpp"

int main(void)
{
	Bureaucrat sandrine = Bureaucrat("Sandrine", 4);
	
	std::cout << sandrine;

	std::cout << std::endl;
	Intern intern = Intern();

	Form* formList[4];
	formList[0] = intern.makeForm("presidential pardon", "Michael");
	std::cout << std::endl;
	formList[1] = intern.makeForm("robotomy request", "David");
	std::cout << std::endl;
	formList[2] = intern.makeForm("shrubbery creation", "Elies");
	std::cout << std::endl;
	formList[3] = intern.makeForm("unknow form", "Elies");

	std::cout << std::endl;
	try {
		sandrine.signForm(*formList[0]);
		sandrine.signForm(*formList[1]);
		sandrine.signForm(*formList[2]);

		std::cout << std::endl;
		sandrine.executeForm(*formList[0]);
		std::cout << std::endl;
		sandrine.executeForm(*formList[1]);
		std::cout << std::endl;
		sandrine.executeForm(*formList[2]);

	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << formList[3] << std::endl;
	delete (formList[0]);
	delete (formList[1]);
	delete (formList[2]);
	return 0;
}
