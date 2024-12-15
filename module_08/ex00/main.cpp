/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:30:13 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 19:45:45 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

int main(void) {

	std::cout << "VECTOR TEST" << std::endl;
	std::vector<int> vec;

	for (std::size_t i = 1; i < 11; i++) {
		vec.push_back(i);
	}

	try {
		std::vector<int>::iterator it;

		for (std::size_t i = 1; i < 11; i++) {
			it = easyfind(vec, i * 2);
			std::cout << "Easyfind finds: " << *it << std::endl;
		}
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "\nDEQUE TEST" << std::endl;
	std::deque<int> deq;

	for (std::size_t i = 1; i < 11; i++) {
		deq.push_back(i);
	}

	try {
		std::deque<int>::iterator it;

		for (std::size_t i = 1; i < 11; i++) {
			it = easyfind(deq, i * 2);
			std::cout << "Easyfind finds: " << *it << std::endl;
		}
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "\nLIST TEST" << std::endl;
	std::list<int> lst;

	for (std::size_t i = 1; i < 11; i++) {
		lst.push_back(i);
	}

	try {
		std::list<int>::iterator it;

		for (std::size_t i = 1; i < 11; i++) {
			it = easyfind(lst, i * 2);
			std::cout << "Easyfind finds: " << *it << std::endl;
		}
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
