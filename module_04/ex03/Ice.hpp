/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:45:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 21:06:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice :
	public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &ice);
		Ice &operator=(const Ice &ice);
		~Ice(void);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif /* ICE_HPP */
