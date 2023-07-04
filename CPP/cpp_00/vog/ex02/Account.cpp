#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;

	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";amount:" << this->_amount \
			  << ";created" << std::endl;
}
Account::Account()  {
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = 0;
}
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";amount:" << this->_amount \
			  << ";closed" << std::endl;
}
int Account::getNbAccounts() {
	return _nbAccounts;
}
int	Account::getTotalAmount() {
	return _totalAmount;
}
int	Account::getNbDeposits() {
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts \
			  << ";total:" << Account::_totalAmount \
			  << ";deposits:" << Account::_totalNbDeposits \
			  << ";withdrawals:" << Account::_totalNbWithdrawals
			  << std::endl;
}
void Account::makeDeposit(int deposit) {
	int new_amount = this->_amount + deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";p_amount:" << this->_amount \
			  << ";deposit:" << deposit \
			  << ";amount:" << new_amount \
			  << ";nb_deposits:" << this->_nbDeposits \
			  << std::endl;

	this->_amount = new_amount;
	this->_totalAmount += deposit;
}
bool Account::makeWithdrawal(int withdrawal) {
	int new_amount = this->_amount - withdrawal;

	_displayTimestamp();
	if(withdrawal > this->_amount) {
		std::cout << "index:" << this->_accountIndex \
				  << ";p_amount:" << this->_amount \
				  << ";withdrawal:refused" \
				  << std::endl;
		return 1;
	}
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex \
			  << ";p_amount:" << this->_amount \
			  << ";withdrawal:" << withdrawal \
			  << ";amount:" << new_amount \
			  << ";nb_withdrawals:" << this->_nbWithdrawals \
			  << std::endl;
	this->_amount = new_amount;
	this->_totalAmount -= withdrawal;
	return 0;
}
int Account::checkAmount() const {
	return this->_amount;
}
void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";amount:" << this->_amount \
			  << ";deposits:" << this->_nbDeposits \
			  << ";withdrawals:" << this->_nbWithdrawals \
			  << std::endl;
}
void Account::_displayTimestamp() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "["
		<< (now->tm_year + 1900)
		<< (now->tm_mon + 1)
		<<  now->tm_mday
		<< "_"
		<< now->tm_hour
		<< now->tm_min
		<< now->tm_sec
		<< "] ";
}