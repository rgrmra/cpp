/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:32:09 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 15:40:40 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "whatever.hpp"

int main(void) {

	std::cout << "INTEGER TEST" << std::endl;

	int a = 10;
	int b = 20;

	std::cout << "a: " << a << ", b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;

	std::cout << "min: " << min(a, b) << std::endl;
	std::cout << "max: " << max(a, b) << std::endl;

	std::cout << "\nSTRING TEST" << std::endl;

	std::string c = "first";
	std::string d = "last";

	std::cout << "a: " << c << ", b: " << d << std::endl;
	swap(c, d);
	std::cout << "a: " << c << ", b: " << d << std::endl;

	std::cout << "min: " << min(c, d) << std::endl;
	std::cout << "max: " << max(c, d) << std::endl;

	return EXIT_SUCCESS;
}
