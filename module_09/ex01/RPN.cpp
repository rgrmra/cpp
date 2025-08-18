/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:14:25 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/18 12:27:16 by rgrmra           ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stack>
#include <string>

RPN::RPN(void) {

}

RPN::RPN(const RPN &src) {

	*this = src;
}

RPN &RPN::operator=(const RPN &rhs) {

	if (this == &rhs)
		return *this;

	return *this;
}

RPN::~RPN(void) {

}

void RPN::push(const std::string &value) {

	if (value.find_first_not_of("0123456789") != std::string::npos)
		throw std::exception();

	double number = std::strtod(value.c_str(), NULL);

	stack.push(number);
}

double RPN::pop(void) {

	if (stack.empty())
		throw std::exception();

	double value = stack.top();

	stack.pop();

	return value;
}

std::string RPN::replace(const std::string &buffer, const char &from, const char &to) {
	
	std::string str = buffer;

	for (size_t i = 0; i < buffer.length(); i++)
		if (buffer.at(i) == from)
			str.at(i) = to;

	return str;
}

void RPN::evaluate(std::istringstream &iss) {

	std::string value;
	if (!getline(iss, value, ' '))
		return;

	size_t size = value.size();
	if (size) {

		if (size > 1)
			throw std::exception();

		if (value == "*")
			operation(std::multiplies<double>());
		else if (value == "/")
			operation(std::divides<double>());
		else if (value == "+")
			operation(std::plus<double>());
		else if (value == "-")
			operation(std::minus<double>());
		else
			push(value);
	}

	evaluate(iss);
}

double RPN::calculate(const std::string &expression) {

	stack = std::stack<double>();

	std::string buffer = expression;
	buffer = replace(buffer, '\t', ' ');
	buffer = replace(buffer, '\n', ' ');
	buffer = replace(buffer, '\v', ' ');
	buffer = replace(buffer, '\f', ' ');
	buffer = replace(buffer, '\r', ' ');

	std::istringstream iss(buffer);
	evaluate(iss);

	if (stack.size() != 1)
		throw std::exception();

	return pop();
}
