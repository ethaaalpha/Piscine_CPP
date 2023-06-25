#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(int initial_deposit)
{
	this->_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;	

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << checkAmount() << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount <= withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
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
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t t = std::time(NULL);
	std::tm		*ltime = std::localtime(&t);

	std::cout << "[";
	std::cout << std::setw(4) << ltime->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << ltime->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << ltime->tm_mday << '_';
	std::cout << std::setfill('0') << std::setw(2) << ltime->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << ltime->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << ltime->tm_sec;
	std::cout << "] ";
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
