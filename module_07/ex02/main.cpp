/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:46:45 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/19 17:30:05 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
	
#include "Array.hpp"
#include <cstddef>
#include <exception>
#include <iostream>

int main(void) {

	std::cout << "DEFAULT CONSTRUCTOR TEST" << std::endl;
	Array<int> *arr1 = new Array<int>();
	std::cout << "size: " << arr1->size() << std::endl;
	std::cout << *arr1 << std::endl;

	std::cout << "\nDEFAULT PARAMETERIZED CONSTRUCTOR TEST" << std::endl;
	Array<int> *arr2 = new Array<int>(5);
	std::cout << "size: " << arr2->size() << std::endl;
	std::cout << "arr2: " << *arr2 << std::endl;
	for (std::size_t i = 0; i < arr2->size(); i++)
		(*arr2)[i] = i + 1;
	std::cout << "arr2: " << *arr2 << std::endl;

	std::cout << "\nCOPY CONSTRUCTOR TEST" << std::endl;
	Array<int> *arr3 = new Array<int>(*arr2);

	std::cout << "arr2: " << *arr2 << std::endl;
	std::cout << "arr3: " << *arr3 << std::endl;

	for (std::size_t i = 0; i < arr2->size(); i++)
		(*arr2)[i] *= 2;

	(*arr3)[1] = 42;

	std::cout << "arr2: " << *arr2 << std::endl;
	std::cout << "arr3: " << *arr3 << std::endl;

	std::cout << "\nCOPY ASSIGNMENT OPERATOR TEST" << std::endl;

	Array<int> arr4 = *arr3;

	std::cout << "arr3: " << *arr3 << std::endl;
	std::cout << "arr4: " << arr4 << std::endl;

	for (std::size_t i = 0; i < arr3->size(); i++)
		(*arr3)[i] *= 2;

	arr4[2] = 42;

	std::cout << "arr3: " << *arr3 << std::endl;
	std::cout << "arr4: " << arr4 << std::endl;

	std::cout << "\nINDEX OUT OF BOUNDS" << std::endl;

	try {
		std::cout << (*arr2)[6] << std::endl;
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}

	delete arr1;
	delete arr2;
	delete arr3;
	
  	return 0;
}
