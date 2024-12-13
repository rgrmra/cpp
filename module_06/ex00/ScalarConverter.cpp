/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:14:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/13 19:50:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

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

void ScalarConverter::convert(std::string str) {

	bool check = true;
	char *rest = NULL;
	double nb = std::strtod(str.c_str(), &rest);

	if (str.size() == 1 && not std::isdigit(str.at(0)))
		nb = static_cast<char>(str.at(0));
	else if (not std::strlen(rest)
		&& static_cast<ssize_t>(str.find_last_not_of("-+0123456789")) != -1)
		nb = std::atoi(str.c_str());
	else if ((std::strlen(rest) == 1 && rest[0] == 'f' && str.find("."))
		|| str == "-inff" || str == "inff" || str == "+inff" || str == "nanf")
		nb = std::strtof(str.c_str(), NULL);
	else if ((not std::strlen(rest) && str.size() && str.find("."))
		|| str == "-inf" || str == "inf" || str == "+inf" || str == "nan")
		nb = std::strtod(str.c_str(), NULL);
	else
		check = false;

	if (check && nb >= CHAR_MIN && nb <= CHAR_MAX) {
		if (std::isprint(static_cast<char>(nb)))
			std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else
		std::cout << "char: impossible" << std::endl;

	if (check && nb >= INT_MIN && nb <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if ((check && nb >= -FLT_MAX && nb <= FLT_MAX) || std::isnan(nb)) {
		std::cout << "float: " << static_cast<float>(nb)
			<< ((static_cast<int>(nb) == nb) ? ".0f" : "f") << std::endl;
	} else
		std::cout << "float: impossible" << std::endl;

	if ((check && nb >= -DBL_MAX && nb <= DBL_MAX) || std::isnan(nb))
		std::cout << "dobule: " << static_cast<double>(nb) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}
