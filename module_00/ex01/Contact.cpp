/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:22:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/08 17:17:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

Contact::Contact() {}

Contact::~Contact() {}

void Contact::set_first_name(const std::string& first_name)
{
	_first_name = first_name;
}

std::string Contact::get_first_name()
{
	return _first_name;
}

void Contact::set_last_name(const std::string& last_name)
{
	_last_name = last_name;
}

std::string Contact::get_last_name()
{
	return _last_name;
}

void Contact::set_nickname(const std::string& nickname)
{
	_nickname = nickname;
}

std::string Contact::get_nickname()
{
	return _nickname;
}

void Contact::set_phone_number(const std::string& phone_number)
{
	_phone_number = phone_number;
}

std::string Contact::get_phone_number()
{
	return _phone_number;
}

void Contact::set_darkest_secret(const std::string& darkest_secret)
{
	_darkest_secret = darkest_secret;
}

std::string Contact::get_darkest_secret()
{
	return _darkest_secret;
}
