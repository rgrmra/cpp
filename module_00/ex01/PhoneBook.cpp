/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:37:42 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/08 17:27:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void) :
	_index(0)
{}

PhoneBook::~PhoneBook(void)
{}

size_t PhoneBook::_get_index()
{
	return _index % CONTACTS_LIMIT;
}

bool PhoneBook::_is_valid_input(std::string &input, int (*function)(int))
{
	for (size_t	i = 0; i < input.length(); i++)
	{
		if (not function(input.at(i)))
			return false;
	}
	return true;
}

void PhoneBook::_add_first_name()
{
	std::string input = _prompt.get_line(COLOR "First name: " RESET);

	if (not _is_valid_input(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid first name!" RESET
			<< std::endl << std::endl;
		return _add_first_name();
	}

	_contacts[_get_index()].set_first_name(input);
}

void PhoneBook::_add_last_name()
{
	std::string input = _prompt.get_line(COLOR "Last name: " RESET);

	if (not _is_valid_input(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid last name!" RESET
			<< std::endl << std::endl;
		return _add_last_name();
	}

	_contacts[_get_index()].set_last_name(input);
}

void PhoneBook::_add_nickname()
{
	std::string input = _prompt.get_line(COLOR "Nickname: " RESET);

	if (not _is_valid_input(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid nickname!" RESET
			<< std::endl << std::endl;
		return _add_nickname();
	}

	_contacts[_get_index()].set_nickname(input);
}

void PhoneBook::_add_phone_number()
{
	std::string input = _prompt.get_line(COLOR "Phone number: " RESET);

	if (not _is_valid_input(input, std::isdigit))
	{
		std::cout << std::endl
			<< RED "Invalid phone number!" RESET
			<< std::endl << std::endl;
		return _add_phone_number();
	}

	_contacts[_get_index()].set_phone_number(input);
}

void PhoneBook::_add_darkest_secret()
{
	std::string input = _prompt.get_line(COLOR "Darkest secret: " RESET);

	if (not _is_valid_input(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid darkest secret!" RESET
			<< std::endl << std::endl;
		return _add_darkest_secret();
	}

	_contacts[_get_index()].set_darkest_secret(input);
}

void PhoneBook::add_contact()
{
	std::cout << std::endl;

	_add_first_name();
	_add_last_name();
	_add_nickname();
	_add_phone_number();
	_add_darkest_secret();

	_index++;

	std::cout << std::endl;
}

void PhoneBook::_set_wfill(std::string str)
{
	if (str.size() > TABLE_WIDTH)
	{
		std::cout
			<< std::setw(TABLE_WIDTH - 1)
			<< str.substr(0, TABLE_WIDTH - 1)
			<< ".|";
	}
	else
	{
		std::cout
			<< std::setw(TABLE_WIDTH)
			<< std::setfill(' ')
			<< str << "|";
	}
}

bool PhoneBook::_display_contacts()
{

	if (!_index)
	{
		std::cout << std::endl << YELLOW "PhoneBook is empty" RESET
			<< std::endl << std::endl;
		return false;
	}

	std::cout << std::endl << "|";
	_set_wfill("Index");
	_set_wfill("First Name");
	_set_wfill("Last Name");
	_set_wfill("Nickname");
	std::cout << RESET << std::endl;

	for (int i = 0; i < CONTACTS_LIMIT; i++)
	{
		if (_contacts[i].get_nickname().empty())
			continue;

		std::cout << LINE << "|"
			<< std::setw(TABLE_WIDTH)
			<< std::setfill(TABLE_FILL)
			<< (i + 1) << "|";
		_set_wfill(_contacts[i].get_first_name());
		_set_wfill(_contacts[i].get_last_name());
		_set_wfill(_contacts[i].get_nickname());
		std::cout << RESET << std::endl;
	}

	std::cout << std::endl;

	return true;
}

void PhoneBook::search_contact()
{

	if (not _display_contacts())
		return;

	std::string input = _prompt.get_line(COLOR "Choose index: " RESET);
	if (not _is_valid_input(input, std::isdigit))
	{
		std::cout << std::endl
			<< RED "It's not a number!" RESET
			<< std::endl;
		return search_contact();
	}

	std::stringstream stringstream;
	stringstream << input;

	size_t number;
	stringstream >> number;

	if (number > _index || number < 1 || number > CONTACTS_LIMIT)
	{
		std::cout << std::endl
			<< RED "Invalid index" RESET
			<< std::endl;

		return search_contact();
	}

	number--;

	std::cout << std::endl
		<< FNAME << _contacts[number].get_first_name()
		<< std::endl << LNAME << _contacts[number].get_last_name()
		<< std::endl << NNAME << _contacts[number].get_nickname()
		<< std::endl << PHONE << _contacts[number].get_phone_number()
		<< std::endl << SECRET << _contacts[number].get_darkest_secret()
		<< std::endl << std::endl;
}
