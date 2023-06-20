#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
	int		registered;
	int		lineprinted;
public:
	PhoneBook();
	~PhoneBook();
	void	addContact(void);
	void	showContactLimited(int contact_index);
	void	showContactFull(int contact_index);
	void	showAllContacts(void);
	void	resetLines(void);
	void	addLine(int n = 1);
	void	loop(void);
};
#endif