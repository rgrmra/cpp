/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:15:37 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 19:32:36 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

#define MATERIASOURCE_INVENTORY_SIZE 4

class MateriaSource :
	public IMateriaSource
{
	private:
		AMateria *_inventory[MATERIASOURCE_INVENTORY_SIZE];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &materiasource);
		MateriaSource &operator=(const MateriaSource &materiasource);
		~MateriaSource(void);

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif /* MATERIASOURCE_HPP */
