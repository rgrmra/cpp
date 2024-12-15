/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:54:49 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/14 20:21:56 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {

	Data *data = new Data();
	data->setFirstName("42");
	data->setLastName("São Paulo");

	uintptr_t ptr = 0;

	std::cout << "Data before serialize" << std::endl;
	std::cout << *data << std::endl;
	std::cout << "uintptr_t: " << ptr << std::endl;

	ptr = Serializer::serialize(data);

	std::cout << "Data after serialize" << std::endl;
	std::cout << "uintptr_t: " << ptr << std::endl;

	Data *testData;

	testData = Serializer::deserializer(ptr);

	std::cout << "Data after deserializer" << std::endl;
	std::cout << *testData << std::endl;
	std::cout << "uintptr_t: " << ptr << std::endl;

	delete data;

	return EXIT_SUCCESS;
}
