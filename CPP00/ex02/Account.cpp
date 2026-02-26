#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account(int initial_deposit)
	: _accountIndex(_nbAccounts)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	++_nbAccounts;
}

~Account(void)
{

}

void makeDeposit(int deposit)
{
	_accountIndex = _nbAccounts;
	_amount = deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";created";

	_totalAmount += deposit;
	
}

bool makeWithdrawal(int withdrawal)
{
index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

int checkAmount(void) const
{

}

void displayStatus(void) const
{
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

void displayAccountsInfos(void)
{
	std::cout << "accounts:" << _nbAccounts 
			  << ";total:" << _totalAmount; 
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals;
}