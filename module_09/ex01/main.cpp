/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:10:20 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/16 16:07:07 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(int argc, char **argv) {

	try {
		if (argc != 2)
			throw std::exception();

		RPN rpn;
		rpn.calculate(argv[1]);
	} catch (std::exception &e) {
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
