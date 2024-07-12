/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:22:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/12 15:06:41 by rde-mour         ###   ########.org.br   */
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

void		Contact::setFirstName(const std::string &firstName)
{
	_firstName = firstName;
}

std::string	Contact::getFirstName(void)
{
	return _firstName;
}

void		Contact::setLastName(const std::string &lastName)
{
	_lastName = lastName;
}

std::string	Contact::getLastName(void)
{
	return _lastName;
}

void		Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

std::string	Contact::getNickname(void)
{
	return _nickname;
}

void		Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber(void)
{
	return _phoneNumber;
}

void		Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
};

std::string	Contact::getDarkestSecret(void)
{
	return _darkestSecret;
}
