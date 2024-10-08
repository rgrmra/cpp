/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:37:42 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/07 21:37:18 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook(void) : _index(0)
{

}

PhoneBook::~PhoneBook(void)
{

}

int	PhoneBook::_getIndex()
{
	return _index % CONTACTS_LIMIT;
}

bool PhoneBook::_invalidInput(std::string &input, int (*function)(int))
{
	for (size_t	i = 0; i < input.length(); i++)
	{
		if (!function(input.at(i)))
			return (true);
	}
	return (false);
}

void	PhoneBook::_addFirstName()
{
	std::string input;

	input = _prompt.getline(COLOR "First name: " RESET);

	if (_invalidInput(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid first name!" RESET
			<< std::endl << std::endl;
		return (_addFirstName());
	}

	_contacts[_getIndex()].setFirstName(input);
}

void	PhoneBook::_addLastName()
{
	std::string input;

	input = _prompt.getline(COLOR "Last name: " RESET);

	if (_invalidInput(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid last name!" RESET
			<< std::endl << std::endl;
		return (_addLastName());
	}

	_contacts[_getIndex()].setLastName(input);
}

void	PhoneBook::_addNickname()
{
	std::string input;

	input = _prompt.getline(COLOR "Nickname: " RESET);

	if (_invalidInput(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid nickname!" RESET
			<< std::endl << std::endl;
		return (_addNickname());
	}

	_contacts[_getIndex()].setNickname(input);
}

void	PhoneBook::_addPhoneNumber()
{
	std::string input;

	input = _prompt.getline(COLOR "Phone number: " RESET);

	if (_invalidInput(input, std::isdigit))
	{
		std::cout << std::endl
			<< RED "Invalid phone number!" RESET
			<< std::endl << std::endl;
		return (_addPhoneNumber());
	}

	_contacts[_getIndex()].setPhoneNumber(input);
}

void	PhoneBook::_addDarkestSecret()
{
	std::string input;

	input = _prompt.getline(COLOR "Darkest secret: " RESET);

	if (_invalidInput(input, std::isprint))
	{
		std::cout << std::endl
			<< RED "Invalid darkest secret!" RESET
			<< std::endl << std::endl;
		return (_addDarkestSecret());
	}

	_contacts[_getIndex()].setDarkestSecret(input);
}

void	PhoneBook::addContact()
{
	std::cout << std::endl;

	_addFirstName();
	_addLastName();
	_addNickname();
	_addPhoneNumber();
	_addDarkestSecret();

	_index++;

	std::cout << std::endl;
}

void PhoneBook::_setWFill(size_t width, char fill, std::string str)
{
	if (str.size() > width)
		std::cout << std::setw(width - 1) << str.substr(0, width - 1) << ".|";
	else
		std::cout << std::setw(width) << std::setfill(fill) << str << "|";
}

bool	PhoneBook::_displayContacts()
{
	const size_t	width = 10;
	const char		fill = ' ';

	if (!_index)
	{
		std::cout << std::endl << YELLOW "PhoneBook is empty" RESET
			<< std::endl << std::endl;
		return false;
	}

	std::cout << std::endl << "|";
	_setWFill(width, fill, "Index");
	_setWFill(width, fill, "First Name");
	_setWFill(width, fill, "Last Name");
	_setWFill(width, fill, "Nickname");
	std::cout << RESET << std::endl;

	for (int i = 0; i < CONTACTS_LIMIT; i++)
	{
		if (_contacts[i].getNickname().empty())
			continue;

		std::cout << LINE << "|";
		std::cout << std::setw(width) << std::setfill(fill) << (i + 1) << "|";
		_setWFill(width, fill, _contacts[i].getFirstName());
		_setWFill(width, fill, _contacts[i].getLastName());
		_setWFill(width, fill, _contacts[i].getNickname());
		std::cout << RESET << std::endl;
	}

	std::cout << std::endl;

	return true;
}

void	PhoneBook::searchContact()
{
	std::string			input;
	std::stringstream	stringstream;
	int					number;

	if (!_displayContacts())
		return;

	input = _prompt.getline(COLOR "Choose index: " RESET);
	if (_invalidInput(input, std::isdigit))
	{
		std::cout << std::endl
			<< RED "It's not a number!" RESET
			<< std::endl;
		return searchContact();
	}

	stringstream << input;
	stringstream >> number;

	if (number > _index || number < 1 || number > CONTACTS_LIMIT)
	{
		std::cout << std::endl
			<< RED "Invalid index" RESET
			<< std::endl;

		return searchContact();
	}

	number--;

	std::cout << std::endl
		<< FNAME << _contacts[number].getFirstName()
		<< std::endl << LNAME << _contacts[number].getLastName()
		<< std::endl << NNAME << _contacts[number].getNickname()
		<< std::endl << PHONE << _contacts[number].getPhoneNumber()
		<< std::endl << SECRET << _contacts[number].getDarkestSecret()
		<< std::endl << std::endl;
}
