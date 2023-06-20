#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	this->_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;	
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << initial_deposit << ";create" << std::endl;
}

Account::~Account()
{
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << checkAmount() << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount <= withdrawal)
		return false;
	else
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals += 1;
		return true;
	}
}

void Account::displayStatus(void) const
{
	// index:7;amount:16596;deposits:1;withdrawals:0
	std::cout << "index:" << this->_accountIndex;
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

void Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
