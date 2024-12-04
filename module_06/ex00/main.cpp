/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:16:35 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/03 18:04:15 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
		return EXIT_FAILURE;
	
	ScalarConverter::convert(argv[1]);

	return EXIT_SUCCESS;
}
