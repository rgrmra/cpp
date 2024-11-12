/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:10:30 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/11 21:37:15 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

#define SCAVTRAP_HIT_POINTS 100
#define SCAVTRAP_ENERGY_POINTS 50
#define SCAVTRAP_ATTACK_DAMAGE 20

class ScavTrap :
	public ClapTrap
{
	private:
		ScavTrap(void);

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap &operator=(const ScavTrap &scavtrap);
		~ScavTrap(void);

		void attack(const std::string &target);

		void guardGate(void);
};

#endif /* SCAVTRAP_HPP */
