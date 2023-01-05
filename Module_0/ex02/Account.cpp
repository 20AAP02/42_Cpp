#include <Account.hpp>
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";\n";
}

void Account::_displayTimestamp(void)
{
	std::time_t result = std::time(NULL);
    std::cout << std::asctime(std::localtime(&result));
}

void Account::makeDeposit(int deposit)
{
	Account::_amount += deposit;
	Account::_nbDeposits += 1;
	Account::_displayTimestamp();
	std::
}

Account::Account(int initial_deposit)
{
	// Acounts static variables
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits += 0; // check

	// Acount itself variables
	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0; // check
	Account::_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created\n";
}

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed\n";
}

Account::Account(void)
{
}