#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat christine = Bureaucrat("Christine", 130);
	Bureaucrat boris = Bureaucrat("Boris", 60);
	Bureaucrat sandrine = Bureaucrat("Sandrine", 4);
	std::cout << christine;
	std::cout << boris;
	std::cout << sandrine;

	std::cout << std::endl;
	PresidentialPardonForm presidential_form = PresidentialPardonForm("Kylie Jenner");
	RobotomyRequestForm robotomy_form = RobotomyRequestForm("Robert Pattinson");
	ShrubberyCreationForm shrubbery_form = ShrubberyCreationForm("Elon Musk");

	std::cout << std::endl;
	christine.executeForm(presidential_form);
	boris.executeForm(presidential_form);
	sandrine.executeForm(presidential_form);

	std::cout << std::endl;
	christine.signForm(presidential_form);
	boris.signForm(presidential_form);
	sandrine.signForm(presidential_form);

	std::cout << std::endl;
	christine.executeForm(presidential_form);
	boris.executeForm(presidential_form);
	sandrine.executeForm(presidential_form);

	std::cout << std::endl;
	sandrine.signForm(robotomy_form);
	sandrine.signForm(shrubbery_form);

	std::cout << std::endl;
	sandrine.executeForm(robotomy_form);
	sandrine.executeForm(shrubbery_form);

	std::cout << std::endl;
	try {
		robotomy_form.execute(boris);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	return 0;
}
