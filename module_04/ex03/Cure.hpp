/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:06:58 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 21:07:19 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure :
	public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &cure);
		Cure &operator=(const Cure &cure);
		~Cure(void);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif /* CURE_HPP */
