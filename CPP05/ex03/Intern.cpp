#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& parent)
{
    std::cout << "Intern default constructor" << std::endl;
    (*this) = parent;
}

Intern& Intern::operator=(const Intern& parent)
{
    (void) parent;
	return (*this);
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor" << std::endl;
}

Form* Intern::makePresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string formType, std::string target)
{
    int i = 0;
    std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    Form* (Intern::*functions[3])(std::string) = {&Intern::makePresident, &Intern::makeRobotomy, &Intern::makeShrubbery};
	
    while (i < 3 && types[i] != formType)
    {    
        i++;
    }
	if (i == 3)
	{
		std::cout << "Error : this type of form isn't existing" << std::endl;
		return (NULL);
	}
    std::cout << "Inter creates " << formType << std::endl;
    return (this->*functions[i])(target);
}
