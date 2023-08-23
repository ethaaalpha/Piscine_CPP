#pragma once
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& parent);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& parent);
	~PresidentialPardonForm(void);

	PresidentialPardonForm(std::string target);
	virtual void execute(Bureaucrat const & executor) const;
};
