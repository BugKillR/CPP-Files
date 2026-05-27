#include "./Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit ) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount += initial_deposit;
	_totalAmount += initial_deposit;
    _displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "amount:" <<_amount;
	std::cout << ";created" << std::endl; 
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit) 
{ 
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount;
	_totalAmount += deposit;
	_nbDeposits++;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
		std::cout << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		std::cout << ";amount:" << _amount;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		return true;
	}
	return false;
}

int		Account::checkAmount(void) const { return _amount; }

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount();
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm *now = std::localtime(&t);

    std::cout << "[";
    std::cout << (now->tm_year + 1900);

    std::cout << std::setw(2) << std::setfill('0')
              << (now->tm_mon + 1);

    std::cout << std::setw(2) << std::setfill('0')
              << now->tm_mday << "_";

    std::cout << std::setw(2) << std::setfill('0')
              << now->tm_hour;

    std::cout << std::setw(2) << std::setfill('0')
              << now->tm_min;

    std::cout << std::setw(2) << std::setfill('0')
              << now->tm_sec;

    std::cout << "]";
}

int		Account::getNbAccounts(void) { return _nbAccounts; }

int		Account::getTotalAmount(void) { return _totalAmount; }

int		Account::getNbDeposits(void) { return _totalNbDeposits; }

int		Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}