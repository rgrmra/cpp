/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:33:44 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 20:36:46 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);

		void set_name(std::string name);
		void announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */
