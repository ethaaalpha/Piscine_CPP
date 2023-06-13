#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name  = last_name;
	this->nick_name  = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	std::cout << "Contact " << this->first_name << " have been created !" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact " << this->first_name << " have been destroyed !" << std::endl;
	return ;
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