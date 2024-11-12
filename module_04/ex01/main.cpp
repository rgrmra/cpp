/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:10:12 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 18:17:11 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	std::cout << "CLASS DOG TESTS" << std::endl;
	
	const Animal *dog = new Dog();
	std::cout << dog->get_type() << std::endl;
	dog->makeSound();
	delete dog;
	
	std::cout << "\nCLASS CAT TESTS" << std::endl;
	const Animal *cat = new Cat();
	std::cout << cat->get_type() << std::endl;
	cat->makeSound();
	delete cat;

	std::cout << "\nSUBJECT TESTS" << std::endl;
    const int ARRAY_SIZE = 4;
    Animal *animals[ARRAY_SIZE];

    for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
    }

    for (size_t i = 0; i < ARRAY_SIZE; ++i)
	{
		std::cout << animals[i]->get_type() << std::endl;
		animals[i]->makeSound();

		delete animals[i];
	}

    std::cout << std::endl;
	std::cout << "Deep copy test" << std::endl;

    Dog basic;
	{
		Dog tmp = basic;
		std::cout << tmp.get_type() << std::endl;
		tmp.makeSound();
	}
	std::cout << basic.get_type() << std::endl;
	basic.makeSound();

  return EXIT_SUCCESS;
}
