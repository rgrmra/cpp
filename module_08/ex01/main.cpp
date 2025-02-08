/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:30:13 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/18 18:25:35 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>

int subjectTest(void) {
	
	std::cout << "SUBJECT TEST" << std::endl;

	Span span = Span(5);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << "shortest: " << span.shortestSpan() << std::endl;
	std::cout << "longest: " << span.longestSpan() << std::endl;

	return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {

	if (argc == 1)
		return subjectTest();

	Span *span = NULL;

	srand(std::time(NULL));
	try {
		if (argc != 5)
			throw std::runtime_error("Span: Usage: ./span <limit> <quantity> <min> <max>");

		int limit = std::atoi(argv[1]);
		int quantity = std::atoi(argv[2]);
		int min = std::atoi(argv[3]);
		int max = std::atoi(argv[4]);

		if (quantity < 1)
			throw std::runtime_error("Span: Exception: Invalid Quantity");

		if (min > max)
			throw std::runtime_error("Span: Exception: min greater than max");

		span = new Span(limit);

		std::cout << "[ ";
		for (int i = 0; i < quantity; i++) {
			int num = min + rand() % (max - min + 1);
			span->addNumber(num);
			std::cout << num << " ";
		}
		std::cout << "]" << std::endl;

		std::cout << "shortest: " << span->shortestSpan() << std::endl;
		std::cout << "longest: " << span->longestSpan() << std::endl;
		
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	if (span)
		delete span;

	return EXIT_SUCCESS;
}
