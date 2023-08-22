#include "Form.hpp"

Form::Form(void) : _name("default"), _status(false), _rank_to_sign(150), _rank_to_use(150)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const Form& parent) : _name(parent.getName())
{
	std::cout << "Form parent constructor" << std::endl;
	(*this) = parent;
}

Form& Form::operator=(const Form& parent)
{
	// same here can't change name because it's const
	_status = parent._status;
	_rank_to_sign = parent._rank_to_sign;
	_rank_to_use = parent._rank_to_use;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor" << std::endl;
}

Form::Form(const std::string name, unsigned int rank_to_sign, unsigned int rank_to_use) : _name(name), _status(false), _rank_to_sign(rank_to_sign), _rank_to_use(rank_to_use)
{
	std::cout << "Form complete constructor" << std::endl;
	if (_rank_to_sign > RANKMIN || _rank_to_use > RANKMIN)
		throw Bureaucrat::GradeTooLowException();
	if (_rank_to_use < RANKMAX || _rank_to_sign < RANKMAX)
		throw Bureaucrat::GradeTooHighException();
}

const std::string Form::getName() const
{
	return (_name);
}

unsigned Form::getRankToSign() const
{
	return (_rank_to_sign);
}

unsigned Form::getRankToUse() const
{
	return (_rank_to_use);
}
	
bool Form::getStatus() const
{
	return (_status);
}

void Form::beSigned(Bureaucrat &user)
{
	if (user.getRank() <= _rank_to_sign)
		std::cout << user.getName() << " signed " << getName() << std::endl;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getRank() > getRankToUse())
		throw (Bureaucrat::GradeTooLowException());
	else
		std::cout << executor.getName() << " executed " << getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, Form &form)
{
	os << "Form : " << form.getName() << ", actual state : " << form.getStatus() << ", level required to sign : " << form.getRankToSign() << ", level required to execute : " << form.getRankToUse() << std::endl;
	return (os);
}