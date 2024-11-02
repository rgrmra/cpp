/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:25:00 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 21:27:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat :
	public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &wrongcat);
		WrongCat &operator=(const WrongCat &wrongcat);
		~WrongCat(void);

		void makeSound(void) const;
};

#endif /* WRONGCAT_HPP */
