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
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor" << std::endl;
}

Form* Intern::makeForm(std::string formType, std::string target)
{
    int i = 0;
    std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    void (*functions[3])() const = (&Form::pre, &RobotomyRequestForm::RobotomyRequestForm(target), &ShrubberyCreationForm::ShrubberyCreationForm(target));

    while (types[i] != formType && i > 2)
        i++;
    switch (i)
    {
    case 0:
        functions[0]();
        std::cout << "Inter creates " << formType << std::endl;
        break;
    case 1:
        functions[1]();
        std::cout << "Inter creates " << formType << std::endl;
        break;
    case 2:
        functions[2]();
        std::cout << "Inter creates " << formType << std::endl;
        break;
    default:
        std::cout << "Error : this type of form isn't existing "
        break;
    }
}
