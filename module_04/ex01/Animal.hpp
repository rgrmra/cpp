/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:57:48 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 21:15:42 by rde-mour         ###   ########.org.br   */
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

		const std::string get_type(void) const;

		virtual void makeSound(void) const;
};

#endif /* ANIMAL_HPP */
