/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:43:30 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 20:21:48 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

int main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("fire");
	me->equip(tmp);

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(0, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
	delete tmp;

	return EXIT_SUCCESS;
}
