#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& parent) : Form("PresidentialPardonForm", 25, 5)
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

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm named constructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << _target << " was forgiven by Zaphod Beeblebrox" << std::endl;
}
