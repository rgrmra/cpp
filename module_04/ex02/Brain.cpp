/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:31:55 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/12 09:35:29 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout
		<< "Brain default constructor called"
		<< std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout
		<< "Brain copy constructor called"
		<< std::endl;

	for (size_t i = 0; i < BRAIN_SIZE_IDEAS; i++)
		_ideas[i] = brain._ideas[i];

	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout
		<< "Brain copy assignment operator called"
		<< std::endl;
	
	if (this == &brain)
		return *this;

	for (size_t i = 0; i < BRAIN_SIZE_IDEAS; i++)
		_ideas[i] = brain._ideas[i];

	return *this;
}

Brain::~Brain(void)
{
	std::cout
		<< "Brain destructor called"
		<< std::endl;
}
