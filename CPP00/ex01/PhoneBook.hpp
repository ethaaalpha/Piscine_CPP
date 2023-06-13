#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
public:
	PhoneBook();
	~PhoneBook();
	void	addContact(Contact new_contact);
	void	showContacts(void);
	void	searchContact(int index);
};
#endif