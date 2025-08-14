/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:30:13 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/14 14:56:58 by rde-mour         ###   ########.org.br   */
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
			throw std::runtime_error("span: Usage: ./span <size> <quantity> <min> <max>");

		long size = std::atoi(argv[1]);
		long quantity = std::atoi(argv[2]);
		long min = std::atoi(argv[3]);
		long max = std::atoi(argv[4]);

		if (quantity < 1)
			throw std::runtime_error("span: Exception: Invalid Quantity");

		if (min > max)
			throw std::runtime_error("span: Exception: min greater than max");

		span = new Span(size);

		std::cout << "[ ";
		for (int i = 0; i < quantity; i++) {
			long num = min + rand() % (max - min + 1);
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
