#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _rank(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& parent) : _name(parent.getName())
{
	std::cout << "Bureaucrat parent constructor" << std::endl;
	(*this) = parent;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& parent)
{
	// can't change _name because it's const !
	_rank = parent.getRank();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int rank) : _name(name) , _rank(rank)
{
	std::cout << "Bureaucrat complete constructor" << std::endl;
	if (_rank < RANKMAX)
		throw (Bureaucrat::GradeTooHighException());
	if (_rank > RANKMIN)
		throw (Bureaucrat::GradeTooLowException());
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int Bureaucrat::getRank(void) const
{
	return (_rank);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high (1 - 150)");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low (1 - 150)");
}

void Bureaucrat::rankDown(void)
{
	if (_rank + 1 > RANKMIN)
		throw (Bureaucrat::GradeTooLowException());
	_rank = _rank + 1;
	std::cout << "Bureaucrat " << getName() << " lose a rank, actual rank " << getRank() << std::endl;
}

void Bureaucrat::rankUp(void)
{
	if (_rank - 1 < RANKMAX)
		throw (Bureaucrat::GradeTooHighException());
	_rank = _rank - 1;
	std::cout << "Bureaucrat " << getName() << " win a rank, actual rank " << getRank() << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
	} catch (Bureaucrat::GradeTooLowException e){
		std::cout << getName() << " couldn't sign " << form.getName() << " because his rank is too low !" << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try {
		form.execute(*this);
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because his rank is took low" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat &bc)
{
	os << bc.getName() << ", bureaucrat grade " << bc.getRank() << std::endl;
	return (os);
}