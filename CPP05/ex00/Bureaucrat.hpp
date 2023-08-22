#pragma once
#include <exception>
#include <iostream>
#define RANKMIN 150
#define RANKMAX 1

class Bureaucrat
{
private:
	const std::string 	_name;
	unsigned int 		_rank;

public:
	//Canonic form
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& parent);
	Bureaucrat& operator=(const Bureaucrat& parent);
	~Bureaucrat(void);

	//Constructor
	Bureaucrat(std::string name, unsigned int rank);

	//Accessers and Setters
	const std::string getName(void) const;
	unsigned int getRank(void) const;
	void rankUp(void);
	void rankDown(void);

	//Exceptions classes
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

//Iostream
std::ostream& operator<<(std::ostream& os, Bureaucrat &bc);