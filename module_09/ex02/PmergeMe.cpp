/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:36:02 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/20 17:39:48 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

PmergeMe::PmergeMe(void) {

}

PmergeMe::PmergeMe(const PmergeMe &src) {

	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {

	if (this == &rhs)
		return *this;

	return *this;
}

PmergeMe::~PmergeMe(void) {

}

int PmergeMe::jacobSthal(const int &value) {

	if (value <= 0)
		return 0;
	if (value == 1)
		return 1;

	int a = 0;
	int b = 1;
	int result;

	for (int i = 2; i <= value; ++i) {
		result = b + 2 * a;
		a = b;
		b = result;
	}
	return b;
}

void PmergeMe::merge(const size_t &level) {

	for (size_t i = level - 1; i + level < _vector.size(); i += level * 2) {
//		std::cout << _vector[i] << " " << _vector[i + level] << std::endl;
		if (_vector[i] <= _vector[i + level])
			continue;

		size_t a = i + 1 - level;
		size_t b = i + 1;

		for (size_t j = 0; j < level; ++j)
			std::swap(_vector[a + j], _vector[b + j]);
//		std::cout << _vector[i] << " " << _vector[i + level]  << "<>" << std::endl;
	}
	if (level * 2 > _vector.size() - level)
		return;

	merge(level * 2);
	insert(level);
}

std::vector<int>::iterator binarySearchLevel(std::vector<int> &vec, int target, size_t level, size_t length) {

	if (vec.empty() || level == 0)
		return vec.end();

	size_t low = 0;
	size_t high = length / level - 1;
	size_t pos = 0;
	while (low <= high) {
		size_t mid = low + (high - low) / 2;
		if (mid > length)
			return vec.begin();
		
		pos = (mid == 0) ? level - 1 : mid * level - 1;
		std::cout << "low: " << low << std::endl;
		std::cout << "high: " << high << std::endl;
		std::cout << "mid: " << mid << std::endl;
		std::cout << "binary: " << pos << std::endl;
		if (vec[pos] == target)
			return vec.begin() + (mid * level);

		if (vec[pos] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	//if (vec[pos] > target)
	//	return vec.begin() + (low * level - level);
	return vec.begin() + (low * level);
    //size_t count = (length + level - 1) / level; // nº de blocos
    //size_t left = 0;
    //size_t right = count;

    //while (left < right) {
    //    size_t mid = left + (right - left) / 2;
    //    std::vector<int>::iterator it = vec.begin() + mid * level;

    //    if (*it < target)
    //        left = mid + level;
    //    else
    //        right = mid;
    //}

    //size_t pos = left * level;
    //if (pos > length) pos = length; // garante que não passa do limite

    //return vec.begin() + pos;
}

void PmergeMe::insert(const size_t &level) {

	std::vector<int> main;

	for (size_t i = 0; i < level * 2; ++i)
		main.push_back(_vector[i]);

	for (size_t i = level * 4 - 1; i < _vector.size(); i += level * 2) {

		size_t a = i + 1 - level;

		for (size_t j = 0; j < level; ++j)
			main.push_back(_vector[a + j]);
	}

	std::cout << "main: "; print_container(main);

	int index = 3;
	int jacob_sthal_prev;
	int jacob_sthal_next;

	size_t insertions = 0;

	while (main.size() + level < _vector.size()) {
	
		if (insertions == 0) {
			jacob_sthal_prev = jacobSthal(index - 1);
			jacob_sthal_next = jacobSthal(index++);
			insertions = jacob_sthal_next - jacob_sthal_prev;
			std::cout << jacob_sthal_prev << " " << jacob_sthal_next << std::endl;
		}

		size_t tmp = jacob_sthal_next;
		while (insertions > 0) {
			
			for (size_t i = (tmp * 2 - 2) * level; i < (tmp * 2 - 1) * level; ++i) {
				if (i < _vector.size()) {
					if (i == (tmp * 2 - 1) * level - 1) {
						size_t ignore = ((_vector.size() / 2) / level - (i / level / 2 + 1) + 1);
						std::vector<int>::iterator it = binarySearchLevel(main, _vector[i], level, main.size() - ignore);
						std::cout << "main size: " << main.size() << std::endl;
						std::cout << "search: " << _vector[i] << std::endl;
						std::cout << "level: " << level << std::endl;
						std::cout << "as: " << (_vector.size() / 2) / level << std::endl;
						std::cout << "b: " << i / level / 2 + 1 << std::endl;
						std::cout << "ignore: " << (_vector.size() / 2) / level - (i / level / 2 + 1) + 1 << std::endl;
						std::cout << "ignore size: " << ignore << std::endl;
						std::cout << "i: " << i << std::endl;

						std::cout << "---" << std::endl;
						print_container(_vector);
						print_container(main);
						std::cout << *(it - 1) << std::endl;
						std::cout << *it << std::endl;
						std::cout << *(it + 1) << std::endl;
						std::cout << "---" << std::endl;
						main.insert(it, _vector.begin() + i - level + 1, _vector.begin() + i + 1);
						//main.insert(main.begin(), 4, _vector[i]);
					}

				}
			}

			tmp--;
			insertions--;
		}
		std::cout << "main: "; print_container(main);
	}

	for (size_t i = _vector.size() / level * level; i < _vector.size(); i++)
		main.push_back(_vector[i]);

	_vector = main;
	print_container(_vector);
}

void PmergeMe::sort(const std::string &list) {

	_vector.clear();
	_deque.clear();

//	for (int i = 0; i < 25; i++)
//		std::cout << jacobSthal(i) << std::endl;

	std::string input = list;
	for (std::string::size_type i = 0; i < list.size(); ++i)
		if (std::isspace(input[i]))
			input[i] = ' ';

	if (input.find_first_not_of(" 0123456789") != std::string::npos)
		throw std::runtime_error("invalid input");

	std::string value;
	std::istringstream iss(input);
	while (std::getline(iss, value, ' ')) {

		if (value.empty())
			continue;

		char **rest = NULL;
		int number = std::strtod(value.c_str(), rest);
		if (rest)
			throw std::runtime_error("invalid input");

		_deque.push_back(number);
		_vector.push_back(number);
	}

	if (_vector.empty())
		throw std::runtime_error("empty input");

	print_container(_vector);
	merge(1);
	print_container(_vector);
	//print_container(_deque);
	for (size_t i = 1; i < _vector.size(); i++) {
		if (_vector[i - 1] > _vector[i]) {
			std::cout << _vector[i - 1] << " " << _vector[i] << std::endl;
			throw std::runtime_error("unorded");
		}
	}

}
