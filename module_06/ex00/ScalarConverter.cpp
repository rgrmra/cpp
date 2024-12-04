/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:14:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/04 19:28:16 by rde-mour         ###   ########.org.br   */
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
#include <iterator>
#include <limits>
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

void ScalarConverter::convert(std::string str) {

	char *rest;
	double nbr = std::strtod(str.c_str(), &rest);
	int i = static_cast<int>(nbr);
	unsigned char c = 0;

	bool result = validate(str, rest);

	if (str.size() == 1) {
		if (std::isprint(str.at(0)) && not std::isdigit(str.at(0))) {
			nbr = c = static_cast<unsigned char>(str.at(0));
			std::cout << "char: '" << static_cast<char>(str.at(0)) << "'" << std::endl;
		 } else {
			std::cout << "char: Not displayable" << std::endl;
		 }
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	if ((result && nbr >= INT_MIN && nbr <= INT_MAX))
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	else if (c)
		std::cout << "int: " << static_cast<int>(c) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if ((result && nbr >= -FLT_MAX && nbr <= FLT_MAX) || c) {
		std::cout << "float: " << static_cast<float>(nbr)
			<< ((double) i == nbr || c ? ".0f" : "") << std::endl;
	} else if (validatePseudoLiterals(str)) {
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	} else
		std::cout << "float: impossible" << std::endl;

	if ((result && nbr >= -DBL_MAX && nbr <= DBL_MAX) || c) {
		std::cout << "double: " << static_cast<double>(nbr)
			<< ((double) i == nbr || c ? ".0" : "") << std::endl;
	} else if (validatePseudoLiterals(str))
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}
