/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:55:05 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/15 23:44:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}

	try {
		std::string file = argv[1];
		size_t pos = file.find_last_of(".");
		if (pos == std::string::npos)
			throw std::runtime_error("invalid file");

		std::string extension = file.substr(pos);
		if (extension != ".csv")
			throw std::runtime_error("invalid file format: " + extension);

		BitcoinExchange btc;
		btc.loadDatabase("data.csv");
		btc.calculateExchange(argv[1]);
	
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
