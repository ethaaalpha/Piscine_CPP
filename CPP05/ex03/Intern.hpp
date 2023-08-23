#pragma once
#include "Form.hpp"

class Intern
{
private:
	Form* makePresident(std::string target);
	Form* makeRobotomy(std::string target);
	Form* makeShrubbery(std::string target);

public:
    Intern(void);
    Intern(const Intern& parent);
    Intern& operator=(const Intern& parent);
    ~Intern(void);

    Form* makeForm(std::string formType, std::string target);
};
