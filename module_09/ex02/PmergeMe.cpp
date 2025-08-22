/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:36:02 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/22 18:40:24 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <sstream>
#include <string>
#include <vector>

PmergeMe::PmergeMe(void) : level(1) {

}

PmergeMe::PmergeMe(const PmergeMe &src) {

	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {

	if (this == &rhs)
		return *this;

	level = rhs.level;

	return *this;
}

PmergeMe::~PmergeMe(void) {

}

std::pair<int, int> PmergeMe::jacobSthal(const int &value) {

	if (value <= 0)
		return std::make_pair(0, 0);

	if (value == 1)
		return std::make_pair(0, 1);

	int a = 0;
	int b = 1;
	int result;

	for (int i = 2; i <= value; ++i) {
		result = b + 2 * a;
		a = b;
		b = result;
	}

	return std::make_pair(a, b);
}

void PmergeMe::parseInput(const std::string &list) {

	std::string input = list;
	for (std::string::size_type i = 0; i < list.size(); ++i)
		if (std::isspace(input[i]))
			input[i] = ' ';

	if (input.find_first_not_of(" 0123456789") != std::string::npos)
		throw std::runtime_error("invalid input");

	std::string value;
	std::istringstream iss(input);

	while (std::getline(iss, value, ' ')) {

		char **rest = NULL;
		int number = std::strtod(value.c_str(), rest);
		if (rest)
			throw std::runtime_error("invalid input");

		_vector.push_back(number);
		_deque.push_back(number);
	}
}

void PmergeMe::sort(const std::string &list) {

	_vector.clear();
	_deque.clear();

	parseInput(list);

	if (_vector.empty())
		throw std::runtime_error("empty input");

	std::pair<std::clock_t, double> vectorClock;
	std::pair<std::clock_t, double> dequeClock;

	std::cout << "Before:\t"; print_container(_vector);

	vectorClock.first = std::clock();
	vectorMerge();
	vectorClock.second = static_cast<double>(std::clock() - vectorClock.first);

	dequeClock.first = std::clock();
	dequeMerge();
	dequeClock.second = static_cast<double>(std::clock() - dequeClock.first);

	std::cout << "After:\t"; print_container(_vector);

	print_status(_vector, "std::vector<int>", vectorClock);
	print_status(_deque, "std::deque<int>", dequeClock);
}
