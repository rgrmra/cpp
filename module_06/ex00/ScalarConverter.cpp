/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:14:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/11 20:24:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>

#ifndef SCALARCONVERTER_TYPE
enum e_type {
	CHAR = 1,
	INT = 2,
	FLOAT = 4,
	FLOAT_INF = 8,
	DOUBLE = 16,
	DOUBLE_INF = 32,
	NONE = 64
};
#endif /* SCALARCONVERTER_TYPE */

ScalarConverter::ScalarConverter(void) {

}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	if (this == &rhs)
		return *this;

	return *this;
}

ScalarConverter::~ScalarConverter(void) {

}

static enum e_type findType(std::string str) {

	if (str.size() == 1 && not std::isdigit(str.at(0)))
		return CHAR;

	if (str == "-inff" || str == "inff" || str == "+inff" || str == "nanf")
		return FLOAT_INF;

	if (str == "-inf" || str == "inf" || str == "+inf" || str == "nan")
		return DOUBLE_INF;

	if (str.at(0) == '-')
		str = str.substr(1, str.size() - 1);

	if (static_cast<ssize_t>(str.find_first_not_of("0123456789")) == -1)
		return INT;

	if (str.size() > 2 && static_cast<ssize_t>(str.find(".")) != -1
		&& static_cast<size_t>(str.find_first_not_of("0123456789.")) == str.size() - 1
		&& (str.find_first_of(".") == str.find_last_of("."))
		&& str.at(str.size() - 1) == 'f')
		return FLOAT;

	if (static_cast<ssize_t>(str.find_last_not_of("0123456789.")) == -1
		&& (str.find_first_of(".") == str.find_last_of(".")))
		return DOUBLE;

	return NONE;
}

void ScalarConverter::convert(std::string str) {

	e_type type = findType(str);

	double nb = 0;
	if (type & CHAR)
		nb = static_cast<char>(str.at(0));
	else if (type &~ NONE)
		nb = std::strtod(str.c_str(), NULL);

	if (type &~ NONE && nb >= CHAR_MIN && nb <= CHAR_MAX) {
		if (std::isprint(static_cast<char>(nb)))
			std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else
		std::cout << "int: impossible" << std::endl;

	if (type &~ NONE && nb >= INT_MIN && nb <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if ((type &~ NONE && nb >= -FLT_MIN && nb <= FLT_MAX) || type & FLOAT_INF) {
		std::cout << "float: " << static_cast<float>(nb)
			<< ((static_cast<int>(nb) == nb) ? ".0f" : "f") << std::endl;
	} else
		std::cout << "float: impossible" << std::endl;

	if ((type &~ NONE && nb >= -DBL_MIN && nb <= DBL_MAX) || type & (FLOAT_INF | DOUBLE_INF))
		std::cout << "dobule: " << static_cast<double>(nb) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

#undef SCALARCONVERTER_TYPE
