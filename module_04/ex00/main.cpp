/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:10:12 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 17:54:45 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	std::cout << "ANIMAL CLASS TESTS:" << std::endl;
	Animal *animal = new Animal();
	std::cout << animal->get_type() << std::endl;
	animal->makeSound();
	delete animal;

	std::cout << "\nDOG CLASS TESTS:" << std::endl;
	Animal *dog = new Dog();
	std::cout << dog->get_type() << std::endl;
	dog->makeSound();
	delete dog;

	std::cout << "\nCAT CLASS TESTS:" << std::endl;
	Animal *cat = new Cat();
	std::cout << cat->get_type() << std::endl;
	cat->makeSound();
	delete cat;

	std::cout << "\nWRONGANIMAL CLASS TESTS:" << std::endl;
	WrongAnimal *wronganimal = new WrongCat();
	std::cout << wronganimal->get_type() << std::endl;
	wronganimal->makeSound();
	delete wronganimal;

	std::cout << "\nWRONGCAT CLASS TESTS:" << std::endl;
	WrongCat *wrongcat = new WrongCat();
	std::cout << wrongcat->get_type() << std::endl;
	wrongcat->makeSound();
	delete wrongcat;

	return EXIT_SUCCESS;
}
