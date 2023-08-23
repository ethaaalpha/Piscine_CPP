#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& parent) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm parent constructor" << std::endl;
	(*this) = parent;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& parent)
{
	_target = parent._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm named constructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::srand(std::time(NULL));
	int number = std::rand();
	
	std::cout << "* drill's noises *" << std::endl;
	if (number % 2 == 0)
		std::cout << _target << " been robotomised with success" << std::endl;
	else
		std::cout << "attempt of robotomised failed on " << _target << std::endl;
}
