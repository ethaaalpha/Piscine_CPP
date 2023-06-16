#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	std::cout << "Je construis un phonebook" << std::endl;
	return ;
}


PhoneBook::~PhoneBook()
{
	std::cout << "Je detruis un phonebook" << std::endl;
	return ;
}

void	PhoneBook::addContact(Contact new_contact)
{
	if (this->index > 7)
		this->index = 1;
	this->contacts[this->index] = new_contact;
}

void	PhoneBook::showContacts()
{
	
}