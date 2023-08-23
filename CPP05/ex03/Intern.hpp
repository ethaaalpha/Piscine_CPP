#pragma once
#include "Form.hpp"

class Intern
{
public:
    Intern(void);
    Intern(const Intern& parent);
    Intern& operator=(const Intern& parent);
    ~Intern(void);

    Form* makeForm(std::string formType, std::string target);
};
