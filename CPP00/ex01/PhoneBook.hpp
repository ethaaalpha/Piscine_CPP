#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		index;
public:
	PhoneBook();
	~PhoneBook();
	void	addContact(Contact new_contact);
	void	searchContact(std::string contact);
};
#endif