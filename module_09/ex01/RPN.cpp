/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:14:25 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/16 18:08:24 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <utility>

RPN::RPN(void) {

}

RPN::RPN(const RPN &src) {

	*this = src;
}

RPN &RPN::operator=(const RPN &src) {

	if (this == &src)
		return *this;

	return *this;
}

RPN::~RPN(void) {

}

//long sum(const long &number1, const long &number2) {
//
//	int a;
//	int b;
//
//	return a + b;
//}
//
//long sub(const long &number1, const long &number2) {
//
//	int a;
//	int b;
//
//	return a + b;
//}
//
//long mult(const long &number1, const long &number2) {
//
//	int a;
//	int b;
//
//	return a + b;
//}
//
//long div(const long &number1, const long &number2) {
//
//	int a;
//	int b;
//
//	return a + b;
//}


std::string RPN::replace(const std::string &buffer, const char &from, const char &to) {
	
	std::string str = buffer;

	for (size_t i = 0; i < buffer.length(); i++) {
		if (buffer.at(i) == from)
			str.at(i) = to;
	}

	return str;
}

std::pair<bool, std::string> RPN::calculate(const std::string &expression) {

	std::string buffer = expression;
	buffer = replace(buffer, '\t', ' ');
	buffer = replace(buffer, '\n', ' ');
	buffer = replace(buffer, '\v', ' ');
	buffer = replace(buffer, '\f', ' ');
	buffer = replace(buffer, '\r', ' ');

	std::istringstream iss(buffer);
	std::string value;

	while (getline(iss, value, ' ')) {

		std::cout << value << std::endl;
	}

	return std::make_pair(true, "");
}
