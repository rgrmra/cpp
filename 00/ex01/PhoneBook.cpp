/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:37:42 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/02 22:27:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

static bool	invalid(std::string str)
{
	if (str.empty())
	{
		std::clearerr(stdin);
		std::cin.clear();
		return true;
	}
	return false;
}

static std::string	prompt(std::string message)
{
	std::string input;

	do
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
	}
	while (invalid(input));
	return input;
}

void	PhoneBook::add_first_name()
{
	std::string input;

	input = prompt("First name: ");
	this->_contacts[_index].set_first_name(input);
}

void	PhoneBook::add_last_name()
{
	std::string input;

	input = prompt("Last name: ");
	this->_contacts[_index].set_last_name(input);
}

void	PhoneBook::add_nickname()
{
	std::string input;

	input = prompt("Nickname: ");
	this->_contacts[_index].set_nickname(input);
}

void	PhoneBook::add_phone_number()
{
	std::string input;

	input = prompt("Phone number: ");
	this->_contacts[_index].set_phone_number(input);
}

void	PhoneBook::add_darkest_secret()
{
	std::string input;

	input = prompt("Darkest secret: ");
	this->_contacts[_index].set_darkest_secret(input);
}

void	PhoneBook::add_contact()
{
	add_first_name();
	add_last_name();
	add_nickname();
	add_phone_number();
	add_darkest_secret();
	std::cout << this->_index << std::endl;
	this->_index = (this->_index + 1) & 0b0111;
	//std::cout << this->_contacts[_index - 1].get_first_name();
}

void	PhoneBook::search_contact()
{
	for (int i = 0; std::isless(i, 8); i++)
	{
		std::cout << this->_contacts[i].get_first_name();
		std::cout << this->_contacts[i].get_last_name();
		std::cout << this->_contacts[i].get_nickname();
		std::cout << this->_contacts[i].get_phone_number();
		std::cout << this->_contacts[i].get_darkest_secret();
	}
}
