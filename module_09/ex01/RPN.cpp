/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:14:25 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/18 09:28:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdio>
#include <cstdlib>
#include <exception>
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

void RPN::push(const std::string &value) {

	char **rest = NULL;
	double number = strtod(value.c_str(), rest);
	if (rest)
		throw std::exception();

	stack.push(number);
}

double RPN::pop(void) {

	if (stack.empty())
		throw std::exception();

	double value = stack.top();

	stack.pop();

	return value;
}

void RPN::sum(void) {

	int b = pop();
	int a = pop();

	double value = a + b;

	stack.push(value);
}

void RPN::sub(void) {

	int b = pop();
	int a = pop();

	double value = a - b;

	stack.push(value);
}

void RPN::mult(void) {

	int b = pop();
	int a = pop();

	double value = a * b;

	stack.push(value);
}

void RPN::div(void) {

	int b = pop();
	int a = pop();
	
	double value = a / b;

	stack.push(value);
}

std::string RPN::replace(const std::string &buffer, const char &from, const char &to) {
	
	std::string str = buffer;

	for (size_t i = 0; i < buffer.length(); i++) {
		if (buffer.at(i) == from)
			str.at(i) = to;
	}

	return str;
}

double RPN::calculate(const std::string &expression) {

	std::string buffer = expression;
	buffer = replace(buffer, '\t', ' ');
	buffer = replace(buffer, '\n', ' ');
	buffer = replace(buffer, '\v', ' ');
	buffer = replace(buffer, '\f', ' ');
	buffer = replace(buffer, '\r', ' ');

	std::istringstream iss(buffer);
	std::string value;

	while (getline(iss, value, ' ')) {

		if (value.empty())
			continue;

		if (value.size() > 1)
			throw std::exception();

		if (value == "*")
			mult();
		else if (value == "/")
			div();
		else if (value == "+")
			sum();
		else if (value == "-")
			sub();
		else
			push(value);
	}

	if (stack.size() != 1)
		throw std::exception();

	return pop();
}
