/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 19:46:16 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

#define CHARACTER_INVENTORY_SIZE 4

class Character :
	public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[CHARACTER_INVENTORY_SIZE];

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &character);
		Character &operator=(const Character &character);
		~Character(void);

		const std::string &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif /* ICHARACTER_HPP */
