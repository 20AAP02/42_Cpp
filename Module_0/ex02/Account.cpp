#include <Account.hpp>
#include <iostream>
#include <iomanip>

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

int Account::checkAmount(void) const
{
	return Account::_amount;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void Account::_displayTimestamp(void)
{
	time_t currentTime;
	struct tm *localTime;

	time(&currentTime);
	localTime = localtime(&currentTime);
	std::cout << "[";
	std::cout << localTime->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << localTime->tm_sec;
	std::cout << "]";
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	Account::_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "nb_deposits:" << Account::_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	std::cout << "withdrawal:";
	if (Account::checkAmount() >= withdrawal)
	{
		std::cout << withdrawal << ";";
		Account::_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << Account::checkAmount() << ";";
		std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << "\n";
		return true;
	}
	std::cout << "refused\n";
	return false;
}

Account::Account(int initial_deposit)
{
	// Acounts static variables
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	// Acount itself variables
	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
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
	// Acounts static variables
	Account::_nbAccounts += 1;

	// Acount itself variables
	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created\n";
}