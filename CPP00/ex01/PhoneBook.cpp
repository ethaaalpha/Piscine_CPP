#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	std::cout << "Je construis un phonebook" << std::endl;
	return ;
}


PhoneBook::~PhoneBook(void){
	std::cout << "Je detruis un phonebook" << std::endl;
	return ;
}

void	PhoneBook::addContact(Contact new_contact)
{
	if (this->index != NULL)
	{

	}
}
