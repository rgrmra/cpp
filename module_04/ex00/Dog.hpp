/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:19 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 18:28:56 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog :
	public Animal
{
	public:
		Dog(void);
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		~Dog(void);

		void makeSound() const;
};

#endif /* DOG_HPP */
