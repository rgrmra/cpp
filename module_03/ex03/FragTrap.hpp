/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:15:41 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/01 15:34:14 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

#define FRAGTRAP_HIT_POINTS 100
#define FRAGTRAP_ENERGY_POINTS 100
#define FRAGTRAP_ATTACK_DAMAGE 30

class FragTrap :
	virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &fragtrap);
		FragTrap &operator=(const FragTrap &fragtrap);
		~FragTrap();

		void attack(const std::string &target);

		void highFivesGuys(void);
};

#endif /* FRAGTRAP_HPP */
