#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
	int		registered;
public:
	PhoneBook();
	~PhoneBook();
	std::string getEntry(std::string entry_name);
	void		addContact(void);
	void		showContactLimited(int contact_index);
	void		showContactFull(int contact_index);
	void		showAllContacts(void);
	void		loop(void);
};
#endif