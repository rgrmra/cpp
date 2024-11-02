/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:24:18 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/02 11:19:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define BRAIN_SIZE_IDEAS 100

class Brain
{
	private:
		std::string _ideas[BRAIN_SIZE_IDEAS];

	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain(void);
};

#endif /* BRAIN_HPP */
