/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:19 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 11:45:14 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog :
	public Animal
{
	private:
		Brain* _brain;

	public:
		Dog(void);
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		~Dog(void);

		void makeSound() const;
};

#endif /* DOG_HPP */
