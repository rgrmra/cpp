/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:37:42 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/03 21:00:50 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <ostream>
#include <set>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

int	PhoneBook::get_index()
{
	return this->_index % CONTACTS_LIMIT;
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

static std::string	prompt(std::string str)
{
	std::string input;

	do
	{
		std::cout << str;
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
	this->_contacts[get_index()].set_first_name(input);
}

void	PhoneBook::add_last_name()
{
	std::string input;

	input = prompt("Last name: ");
	this->_contacts[get_index()].set_last_name(input);
}

void	PhoneBook::add_nickname()
{
	std::string input;

	input = prompt("Nickname: ");
	this->_contacts[get_index()].set_nickname(input);
}

void	PhoneBook::add_phone_number()
{
	std::string input;

	input = prompt("Phone number: ");
	this->_contacts[get_index()].set_phone_number(input);
}

void	PhoneBook::add_darkest_secret()
{
	std::string input;

	input = prompt("Darkest secret: ");
	this->_contacts[get_index()].set_darkest_secret(input);
}

void	PhoneBook::add_contact()
{
	add_first_name();
	add_last_name();
	add_nickname();
	add_phone_number();
	add_darkest_secret();
	this->_index++; // = (this->_index + 1) & 0b0111;
	//std::cout << this->_index << std::endl;
	//std::cout << this->_contacts[_index - 1].get_first_name();
}

static void setwfill(int width, char fill, std::string str)
{
	std::cout << std::setw(width) << std::setfill(fill) << str << "|";
}

void	PhoneBook::display_contacts()
{
	int		width;
	char	fill;

	if (!this->_index)
		std::cout << "Empty PhoneBook" << std::endl;
	width = 10;
	fill = ' ';
	std::cout << "|";
	setwfill(width, fill, "Index");
	setwfill(width, fill, "First Name");
	setwfill(width, fill, "Last Name");
	setwfill(width, fill, "Nickname");
	std::cout << std::endl;
	for (int i = 0; std::isless(i, CONTACTS_LIMIT); i++)
	{
		if (this->_contacts[i].get_nickname().empty())
			continue ;
		std::cout << "|";
		std::cout << std::setw(width) << std::setfill(fill) << i + 1 << "|";
		setwfill(width, fill, this->_contacts[i].get_first_name());
		setwfill(width, fill, this->_contacts[i].get_last_name());
		setwfill(width, fill, this->_contacts[i].get_nickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::search_contact()
{
	std::string input;

	display_contacts();
	input = prompt(": ");
	//for (int i = 0; std::isless(i, 8); i++)
	//{
	//	std::cout << i + 1 << std::endl;
	//	std::cout << this->_contacts[i].get_first_name() << std::endl;
	//	std::cout << this->_contacts[i].get_last_name() << std::endl;
	//	std::cout << this->_contacts[i].get_nickname() << std::endl;
	//	std::cout << this->_contacts[i].get_phone_number() << std::endl;
	//	std::cout << this->_contacts[i].get_darkest_secret() << std::endl;
	//}
}
