/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:48:53 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/14 20:11:55 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) {

}

Data::Data(std::string firstname, std::string lastname)
	: _firstName(firstname), _lastName(lastname) {

}

Data::Data(const Data &src) {

	*this = src;
}

Data &Data::operator=(const Data &rhs) {

	if (this == &rhs)
		return *this;

	_firstName = rhs._firstName;
	_lastName = rhs._lastName;

	return *this;
}


Data::~Data(void) {

}

void Data::setFirstName(std:: string firstname) {

	_firstName = firstname;
}

std::string Data::getFirstName(void) const {

	return _firstName;
}

void Data::setLastName(std::string lastname) {

	_lastName = lastname;
}


std::string Data::getLastName(void) const {
	
	return _lastName;
}

std::ostream &operator<<(std::ostream &os, const Data &src) {

	return os << "Escola: " + src.getFirstName() + " " + src.getLastName();
}
