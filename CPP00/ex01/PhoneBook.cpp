#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "header.h"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->registered = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(void)
{
	if (this->registered < 8)
		this->registered +=1;
	if (this->index > 7)
		this->index = 0;
	this->contacts[this->index].defineValues(getEntry("firstname"), \
	getEntry("lastname"), \
	getEntry("nickname"), \
	getEntry("phonenumber"), \
	getEntry("darkest secret"));
	this->index += 1;
	std::cout << "Contact successfully added !" << std::endl;
}

std::string PhoneBook::getEntry(std::string entry_name)
{
	std::string input = "\0";

	std::cout << "Please, enter the " << entry_name << " !" << std::endl;
	getline(std::cin, input);
	while (ft_trim(input))
	{
		std::cout << "Error, the " << entry_name << " can't be empty (or filled of space) !" << std::endl;
		getline(std::cin, input);
	}
	return (input);
}

void	PhoneBook::showContactLimited(int contact_index)
{
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << contact_index;

	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << getLimitedInfo(this->contacts[contact_index].getFirstName());

	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << getLimitedInfo(this->contacts[contact_index].getLastName());

	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << getLimitedInfo(this->contacts[contact_index].getNickName());
	std::cout << "|" << std::endl;
}

void	PhoneBook::showContactFull(int contact_index)
{
	std::cout << "FirstName : " << this->contacts[contact_index].getFirstName() << std::endl;
	std::cout << "LastName : " << this->contacts[contact_index].getLastName() << std::endl;
	std::cout << "NickName : " << this->contacts[contact_index].getNickName() << std::endl;
	std::cout << "PhoneNumber : " << this->contacts[contact_index].getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret : " << this->contacts[contact_index].getDarkestSecret() << std::endl;
}

void	PhoneBook::showAllContacts(void)
{
	int	value;
	if (this->registered == 0)
	{
		std::cout << "No contact registered yet !" << std::endl;
		return ;
	}
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "first name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "last name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "nick name" << "|" << std::endl; 
	for (int i = 0; i < this->registered; i++)
		showContactLimited(i);
	while (1)
	{
		std::string entry = getEntry("index of the contact");
		value = std::atoi(entry.c_str());
		if (entry.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Error, the index might only be composed of numbers (0123456789) !" << std::endl;
			continue;
		}
		if (value < 0 || value > this->registered - 1)
		{
			std::cout << "Error, this index isn't registered in the phonebook !" << std::endl;
			continue;
		}
		break ;
	}
	showContactFull(value);
}

void	PhoneBook::loop(void)
{
	std::string input;

	std::cout << "Welcome in your PhoneBook !" << std::endl;
	std::cout << "List of avaible commands :" << std::endl;
	std::cout << "ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		getline(std::cin, input);
		if (input == "ADD")
			addContact();
		else if (input == "SEARCH")
			showAllContacts();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Forbidden command, please use ADD, SEARCH, EXIT" << std::endl;
	}
}