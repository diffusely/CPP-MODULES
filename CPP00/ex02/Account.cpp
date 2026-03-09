#include "Account.hpp"

#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << 
		initial_deposit << ";created" << std::endl;
	_totalAmount += initial_deposit;
	++_nbAccounts;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
				<< ";closed" << '\n';
	--_nbAccounts;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	++_totalNbDeposits;
	++_nbDeposits;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex 
			  << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" <<_amount << ";withdrawal:";

	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}

	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:"
			  << _amount - withdrawal << ";nb_withdrawals:" 
			  << _nbWithdrawals << '\n';

	_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals << "\n";
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() 
			  << ";total:" << getTotalAmount() 
			  << ";deposits:" << getNbDeposits() 
			  << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::_displayTimestamp()
{
	time_t		now;
	struct tm	*timeinfo;
	char		buffer[20];

	now = time(NULL);
	timeinfo = localtime(&now);
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}