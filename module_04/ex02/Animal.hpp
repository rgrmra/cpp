/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:57:48 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 15:17:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		virtual ~Animal(void);

		virtual const std::string get_type(void) const;

		virtual void makeSound(void) const = 0;
};

#endif /* ANIMAL_HPP */
