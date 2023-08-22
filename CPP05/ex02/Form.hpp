#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
private:
	const std::string 	_name;
	bool 				_status;
	unsigned int 		_rank_to_sign;
	unsigned int		_rank_to_use;

public:
	// Canonical form
	Form(void);
	Form(const Form& parent);
	Form& operator=(const Form& parent);
	~Form(void);
	
	// Accessers and setters
	const std::string getName() const;
	unsigned getRankToSign() const;
	unsigned getRankToUse() const;
	bool getStatus() const;

	// Constructor
	Form(const std::string name, unsigned int rank_to_sign, unsigned int rank_to_use);

	// Use
	void beSigned(Bureaucrat &user);
};

//Iostream
std::ostream& operator<<(std::ostream& os, Form &form);
