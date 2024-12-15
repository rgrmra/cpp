/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:16:35 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 14:52:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Too few argumets" << std::endl;
		return EXIT_FAILURE;
	}
	
	ScalarConverter::convert(argv[1]);

	return EXIT_SUCCESS;
}
