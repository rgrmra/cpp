/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:22:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/07 14:51:38 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

Contact::Contact(void)
{
	
}

Contact::~Contact(void)
{
	
}

void		Contact::set_first_name(const std::string &first_name)
{
	this->_first_name = first_name;
}

std::string	Contact::get_first_name(void)
{
	return this->_first_name;
}

void		Contact::set_last_name(const std::string &last_name)
{
	this->_last_name = last_name;
}

std::string	Contact::get_last_name(void)
{
	return this->_last_name;
}

void		Contact::set_nickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

std::string	Contact::get_nickname(void)
{
	return this->_nickname;
}

void		Contact::set_phone_number(const std::string &phone_number)
{
	this->_phone_number = phone_number;
}

std::string	Contact::get_phone_number(void)
{
	return this->_phone_number;
}

void		Contact::set_darkest_secret(const std::string &darkest_secret)
{
	this->_darkest_secret = darkest_secret;
};

std::string	Contact::get_darkest_secret(void)
{
	return this->_darkest_secret;
}
