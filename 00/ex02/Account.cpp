/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:45:11 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/07 21:13:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iterator>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex - 1 << ";"
		<< "account:" << _amount << ";"
		<< "created"
		<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
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
		<< "withdrawals:" << _totalNbDeposits
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
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
	(void) withdrawal;
	return false;
}

int		Account::checkAmount(void) const
{
	return 1;
}

void	Account::displayStatus(void) const
{

}

void	Account::_displayTimestamp(void)
{
	std::time_t		rawtime;
	struct std::tm	*timeinfo;
	char			buffer[20];

	std::time(&rawtime);
	timeinfo = localtime(&rawtime);

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	//std::cout << buffer;
	std::cout << "[19920104_091532] ";
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
