#pragma once
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& parent);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& parent);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(std::string target);
	virtual void execute(Bureaucrat const & executor) const;
};
