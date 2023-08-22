#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& parent) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "PresidentialPardonForm parent constructor" << std::endl;
	(*this) = parent;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& parent)
{
	_target = parent._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "PresidentialPardonForm named constructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	// do what you need to do here
}
