/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:32:09 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/15 16:07:30 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "iter.hpp"

int main(void) {

	std::cout << "INTEGER TEST" << std::endl;

	int numbers[5] = {1, 2, 3, 4, 5};

	iter(numbers, 5, pow<int>);
	iter(numbers, 5, print<int>);

	std::cout << "\nSTRING TEST" << std::endl;

	std::string names[5] = {"42", "Cadet", "Moulinette", "Piscine", "Exam"};

	iter(names, 5, print<std::string>);

	return EXIT_SUCCESS;
}
