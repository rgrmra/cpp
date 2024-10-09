/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:45:11 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/09 18:22:16 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;

	_displayTimestamp();

	std::cout
		<< "index:" << _accountIndex - 1 << ";"
		<< "amount:" << _amount << ";"
		<< "created"
		<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();

	std::cout
		<< "index:" << _accountIndex - 1 << ";"
		<< "amount:" << _amount << ";"
		<< "closed"
		<< std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();

	std::cout
		<< "index:" << _accountIndex - 1 << ";"
		<< "p_amount:" << (_amount - deposit) << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();

		std::cout << "index:" << _accountIndex - 1 << ";"
			<< "p_amount:" << _amount << ";"
			<< "withdrawal:refused"
			<< std::endl;
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();

	std::cout
		<< "index:" << _accountIndex - 1 << ";"
		<< "p_amount:" << (_amount + withdrawal) << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;

	return true;
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout
		<< "index:" << _accountIndex - 1 << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t rawtime;
	std::time(&rawtime);

	struct std::tm *timeinfo;
	timeinfo = localtime(&rawtime);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);

	std::cout << buffer;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
