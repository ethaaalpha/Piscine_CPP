#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
}

Contact::~Contact()
{
	return ;
}

void	Contact::defineValues(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darksecret)
{
	this->first_name = firstname;
	this->last_name  = lastname;
	this->nick_name  = nickname;
	this->phone_number = phonenumber;
	this->darkest_secret = darksecret;
}

std::string Contact::getFirstName(void){
	return this->first_name;
}

std::string Contact::getLastName(void){
	return this->last_name;
}

std::string Contact::getNickName(void){
	return this->nick_name;
}

std::string Contact::getPhoneNumber(void){
	return this->phone_number;
}

std::string Contact::getDarkestSecret(void){
	return this->darkest_secret;
}