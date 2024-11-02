/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:10:12 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 21:56:40 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

int main(void)
{
	Animal *animal = new Animal();

	std::cout << animal->get_type() << std::endl;
	animal->makeSound();

	delete animal;

	std::cout << std::endl;
	Animal *dog = new Dog();

	std::cout << dog->get_type() << std::endl;
	dog->makeSound();

	delete dog;

	std::cout << std::endl;
	Animal *cat = new Cat();

	std::cout << cat->get_type() << std::endl;
	cat->makeSound();

	delete cat;

	std::cout << std::endl;
	WrongAnimal *wronganimal = new WrongCat();

	std::cout << wronganimal->get_type() << std::endl;
	wronganimal->makeSound();

	delete wronganimal;

	return EXIT_SUCCESS;
}
