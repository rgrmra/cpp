/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:37:42 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/08 10:01:15 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

Contact _contacts[CONTACTS_LIMIT];
int		_index;
Prompt	_prompt;

PhoneBook::PhoneBook(void)
{
	_index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

int	PhoneBook::get_index()
{
	return _index % CONTACTS_LIMIT;
}

static bool invalid_input(std::string &input, int (*function)(int))
{
	for (std::string::const_iterator i = input.begin(); i < input.end(); i++)
	{
		if (!function(*i))
			return true;
	}
	return false;
}

void	PhoneBook::add_first_name()
{
	std::string input;

	input = _prompt.getline(COLOR "First name: " RESET);
	if (invalid_input(input, std::isprint))
	{
		std::cout << std::endl << RED << "Invalid first name!" << RESET
			<< std::endl << std::endl;
		return add_first_name();
	}
	_contacts[get_index()].set_first_name(input);
}

void	PhoneBook::add_last_name()
{
	std::string input;

	input = _prompt.getline(COLOR "Last name: " RESET);
	if (invalid_input(input, std::isprint))
	{
		std::cout << std::endl << RED << "Invalid last name!" << RESET
			<< std::endl << std::endl;
		return add_last_name();
	}
	_contacts[get_index()].set_last_name(input);
}

void	PhoneBook::add_nickname()
{
	std::string input;

	input = _prompt.getline(COLOR "Nickname: " RESET);
	if (invalid_input(input, std::isprint))
	{
		std::cout << std::endl << RED << "Invalid nickname!" << RESET
			<< std::endl << std::endl;
		return add_nickname();
	}
	_contacts[get_index()].set_nickname(input);
}

void	PhoneBook::add_phone_number()
{
	std::string input;

	input = _prompt.getline(COLOR "Phone number: " RESET);
	if (invalid_input(input, std::isdigit))
	{
		std::cout << std::endl << RED << "Invalid phone number!" << RESET
			<< std::endl << std::endl;
		return add_phone_number();
	}
	_contacts[get_index()].set_phone_number(input);
}

void	PhoneBook::add_darkest_secret()
{
	std::string input;

	input = _prompt.getline(COLOR "Darkest secret: " RESET);
	if (invalid_input(input, std::isprint))
	{
		std::cout << std::endl << RED << "Invalid darkest secret!" << RESET
			<< std::endl << std::endl;
		return add_darkest_secret();
	}
	_contacts[get_index()].set_darkest_secret(input);
}

void	PhoneBook::add_contact()
{
	std::cout << std::endl;
	add_first_name();
	add_last_name();
	add_nickname();
	add_phone_number();
	add_darkest_secret();
	_index++;
	std::cout << std::endl;
}

static void setwfill(unsigned long width, char fill, std::string str)
{
	if (str.size() > width)
		std::cout << std::setw(width - 1) << str.substr(0, width - 1) << ".|";
	else
		std::cout << std::setw(width) << std::setfill(fill) << str << "|";
}

bool	PhoneBook::display_contacts()
{
	int		width;
	char	fill;

	if (!_index)
	{
		std::cout << std::endl << YELLOW "PhoneBook is empty" RESET
			<< std::endl << std::endl;
		return false;
	}
	width = 10;
	fill = ' ';
	std::cout << std::endl << HEADER "|";
	setwfill(width, fill, "Index");
	setwfill(width, fill, "First Name");
	setwfill(width, fill, "Last Name");
	setwfill(width, fill, "Nickname");
	std::cout << RESET << std::endl;
	for (int i = 0; i < CONTACTS_LIMIT; i++)
	{
		if (_contacts[i].get_nickname().empty())
			continue;
		std::cout << LINE << "|";
		std::cout << std::setw(width) << std::setfill(fill) << i + 1 << "|";
		setwfill(width, fill, _contacts[i].get_first_name());
		setwfill(width, fill, _contacts[i].get_last_name());
		setwfill(width, fill, _contacts[i].get_nickname());
		std::cout << RESET << std::endl;
	}
	std::cout << std::endl;
	return true;
}

void	PhoneBook::search_contact()
{
	std::string			input;
	std::stringstream	ss;
	int					nbr;

	if (!display_contacts())
		return;
	input = _prompt.getline(COLOR "Choose index: " RESET);
	if (invalid_input(input, std::isdigit))
	{
		std::cout << std::endl << RED "It's not a number!" RESET << std::endl;
		return search_contact();
	}
	ss << input;
	ss >> nbr;
	if (nbr > _index || nbr < 1 || nbr > CONTACTS_LIMIT)
	{
		std::cout << std::endl << RED "Invalid index" RESET << std::endl;
		return search_contact();
	}
	nbr--;
	std::cout << std::endl << FNAME << _contacts[nbr].get_first_name()
		<< std::endl << LNAME << _contacts[nbr].get_last_name()
		<< std::endl << NNAME << _contacts[nbr].get_nickname()
		<< std::endl << PHONE << _contacts[nbr].get_phone_number()
		<< std::endl << SECRET << _contacts[nbr].get_darkest_secret()
		<< std::endl << std::endl;
}
