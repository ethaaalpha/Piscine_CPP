#pragma once
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& parent);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& parent);
	~RobotomyRequestForm(void);

	RobotomyRequestForm(std::string target);
	virtual void execute(Bureaucrat const & executor) const;
};
