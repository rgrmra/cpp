/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:36:05 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 11:19:51 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat :
	public Animal
{
	private:
		Brain *_brain;

	public:
		Cat(void);
		Cat(const Cat &cat);
		Cat &operator=(const Cat &cat);
		~Cat(void);

		void makeSound(void) const;
};

#endif /* CAT_HPP */
