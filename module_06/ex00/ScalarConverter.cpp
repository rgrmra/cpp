/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:14:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 20:04:13 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

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

static void printAsChar(double n, bool ok) {

	if (not ok || n < CHAR_MIN || n > CHAR_MAX || std::isnan(n) || std::isinf(n))
		std::cout << "char: impossible" << std::endl;
	else if (not std::isprint(static_cast<char>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
}

static void printAsInt(double n, bool ok) {

	if (not ok || n < INT_MIN || n > INT_MAX || std::isnan(n) || std::isinf(n))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
}

static void printAsFloat(double n, bool ok) {

	if ((ok && n >= -FLT_MAX && n <= FLT_MAX) || std::isnan(n) || std::isinf(n))
		std::cout << "float: "<< static_cast<float>(n)
			<< ((static_cast<int>(n) == n && n <= 999999) ? ".0f" : "f")
			<< std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

static void printAsDouble(double n, bool ok) {

	if ((ok && n >= -DBL_MAX && n <= DBL_MAX) || std::isnan(n) || std::isinf(n))
		std::cout << "double: " << static_cast<double>(n)
			<< ((static_cast<int>(n) == n && n <= 999999) ? ".0" : "")
			<< std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string str) {

	bool ok = true;
	char *rest = NULL;
	double n = std::strtod(str.c_str(), &rest);

	if (str.size() == 1 && not std::isdigit(str.at(0)))
		n = static_cast<char>(str.at(0));
	else if ((std::strlen(rest) == 1 && rest[0] == 'f' && str.find("."))
		|| str == "-inff" || str == "inff" || str == "+inff" || str == "nanf")
		n = std::strtof(str.c_str(), NULL);
	else if ((not std::strlen(rest) && str.size() && str.find("."))
		|| str == "-inf" || str == "inf" || str == "+inf" || str == "nan")
		n = std::strtod(str.c_str(), NULL);
	else if (not std::strlen(rest) && not std::isnan(n) && not std::isinf(n)
			&& static_cast<ssize_t>(str.find_last_not_of("-+0123456789")) != -1)
		n = std::atoi(str.c_str());
	else
		ok = false;

	printAsChar(n, ok);
	printAsInt(n, ok);
	printAsFloat(n, ok);
	printAsDouble(n, ok);
}
