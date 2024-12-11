/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:14:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/10 21:05:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/types.h>

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

bool validatePseudoLiterals(std::string str) {
	
	static const std::string literals[] = {
		"+inff", "inff", "-inff", "nanf",
		"+inf", "inf", "-inf", "nan"
	};

	for (size_t i = 0; i < 8; i++) {
		if (literals[i] == str)
			return true;
	}

	return false;
}

bool validate(std::string &str, char *rest) {

	if (validatePseudoLiterals(str) == true)
		return true;

	if (static_cast<ssize_t>(str.find('.')) == -1
		&& static_cast<ssize_t>(str.find('f')) >= 0)
		return false;

	if (std::strlen(rest) > 1 || (std::strlen(rest) == 1 && rest[0] != 'f'))
		return false;

	return true;
}

std::string convertToChar(std::string &str, double *nbr, char *c) {

	if (str.size() == 1 && std::isprint(str.at(0)) && not std::isdigit(str.at(0))) {
		*nbr = *c = static_cast<char>(str.at(0));

		return "'" + std::string(1, static_cast<char>(str.at(0))) + "'";
	}

	if (*nbr >= CHAR_MIN && *nbr <= CHAR_MAX) {
		if (not std::isprint(static_cast<int>(*nbr)))
			return "Non displayable";

		return "'" + std::string(1, static_cast<int>(*nbr)) + "'";
	}

	return "impossible";
}

std::string convertToInt(std::string &str, double *nbr, char *rest, char *c) {

	std::stringstream ss;

	ss << static_cast<int>(*nbr);
	if (validate(str, rest) && *nbr >= INT_MIN && *nbr <= INT_MAX)
		return ss.str();

	if (*c)
		return ss.str();

	return "impossible";
}

std::string convertToFloat(std::string &str, double *nbr, char *rest, char *c) {

	std::stringstream ss;

	ss << static_cast<float>(*nbr);

	if ((validate(str, rest) && *nbr >= -FLT_MIN && *nbr <= FLT_MAX) || *c) {
		int i = static_cast<int>(*nbr);

		return ss.str() + (((double) i == *nbr || *c) ? ".0f" : "f");
	}

	if (validatePseudoLiterals(str))
		return ss.str() + "f";

	return "impossible";
}

std::string convertToDouble(std::string &str, double *nbr, char *rest, char *c) {

	std::stringstream ss;

	ss << static_cast<float>(*nbr);

	if ((validate(str, rest) && *nbr >= -FLT_MIN && *nbr <= FLT_MAX) || *c) {
		int i = static_cast<int>(*nbr);

		return ss.str() + (((double) i == *nbr || *c) ? ".0" : "");
	}

	if (validatePseudoLiterals(str))
		return ss.str() + "";

	return "impossible";
}

void ScalarConverter::convert(std::string str) {

	char *rest = NULL;
	double nbr = std::strtod(str.c_str(), &rest);
	char c = 0;

	std::cout << "char: " << convertToChar(str, &nbr, &c) << std::endl;

	std::cout << "int: " << convertToInt(str, &nbr, rest, &c) << std::endl;

	std::cout << "float: " << convertToFloat(str, &nbr, rest, &c) << std::endl;

	std::cout << "double: " << convertToDouble(str, &nbr, rest, &c) << std::endl;
}
