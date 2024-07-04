/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:37:42 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/04 20:44:45 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <ostream>
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

static void setwfill(unsigned long width, char fill, std::string str)
{
	if (str.size() > width)
		std::cout << std::setw(width - 1) << str.substr(0, width - 1) << ".|";
	else
		std::cout << std::setw(width) << std::setfill(fill) << str << "|";
}

void	PhoneBook::display_contacts()
{
	int		width;
	char	fill;

	if (!this->_index)
		std::cout << std::endl << "Empty PhoneBook" << std::endl;
	width = 10;
	fill = ' ';
	std::cout << std::endl << "|";
	setwfill(width, fill, "Index");
	setwfill(width, fill, "First Name");
	setwfill(width, fill, "Last Name");
	setwfill(width, fill, "Nickname");
	std::cout << std::endl;
	for (int i = 0; std::isless(i, CONTACTS_LIMIT); i++)
	{
		if (this->_contacts[i].get_nickname().empty())
			continue;
		std::cout << "|";
		std::cout << std::setw(width) << std::setfill(fill) << i + 1 << "|";
		setwfill(width, fill, this->_contacts[i].get_first_name());
		setwfill(width, fill, this->_contacts[i].get_last_name());
		setwfill(width, fill, this->_contacts[i].get_nickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search_contact()
{
	int	num;
	std::string			input;

	display_contacts();
	input = prompt("Choose index: ");
	num = 0;
	for (std::string::const_iterator i = input.begin(); i < input.end(); i++)
	{
		if (!std::isdigit(*i))
		{
			std::cout << "\033[0;91mInvalid number!\033[0;m" << std::endl;
			return search_contact();
		}
		num = num * 10 + *i - '0';
	}
	if (std::isgreater(num, this->_index) || std::isless(num, 1) || std::isgreater(num, CONTACTS_LIMIT))
	{
		std::cout << "Invalid number" << std::endl;
		return search_contact();
	}
	std::cout << FNAME + this->_contacts[--num].get_first_name() << std::endl; 
	std::cout << LNAME + this->_contacts[num].get_last_name() << std::endl;
	std::cout << NNAME + this->_contacts[num].get_nickname() << std::endl;
	std::cout << PHONE + this->_contacts[num].get_phone_number() << std::endl;
	std::cout << SECRET + this->_contacts[num].get_darkest_secret() << std::endl;
}
