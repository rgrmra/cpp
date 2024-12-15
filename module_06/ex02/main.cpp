/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:16:41 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/14 23:18:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base *generate(void) {

	srand(time(0));
	int number = rand() % 3;

	if (number == 0)
		return new A;
	else if (number == 1)
		return new B;
	else
		return new C;
}

void identify(Base *base) {

	if (dynamic_cast<A *>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(base))
		std::cout << "C" << std::endl;
	else if (dynamic_cast<Base *>(base))
		std::cout << "Base" << std::endl;
	else
	 	std::cout << "NULL" << std::endl;
}

void identify(Base &base) {

	try {
		A a = dynamic_cast<A &>(base);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &exception) {

	}

	try {
		B b = dynamic_cast<B &>(base);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &exception) {

	}

	try {
		C c = dynamic_cast<C &>(base);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &exception) {

	}

	try {
		Base ref = dynamic_cast<Base &>(base);
		std::cout << "Base" << std::endl;
		return ;
	} catch (std::exception &exception) {

	}

	std::cout << "NULL" << std::endl;
}

int main(void) {

	Base *base = generate();
	Base &ref = *base;

	identify(base);
	identify(ref);

	delete base;

	return EXIT_SUCCESS;
}
