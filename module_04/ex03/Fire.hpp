/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:46:41 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 19:47:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
#define FIRE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Fire :
	public AMateria
{
	public:
		Fire(void);
		Fire(const Fire &fire);
		Fire &operator=(const Fire &fire);
		~Fire(void);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif /* FIRE_HPP */

