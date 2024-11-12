/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:11:32 by rde-mour          #+#    #+#             */
/*   Updated: 2024/11/11 20:03:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

#define DIAMOND_SUFFIX(name) name.append("_clap_name")

class DiamondTrap :
	public ScavTrap,
	public FragTrap
{
	private:
		std::string _name;
		DiamondTrap(void);

	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &diamondtrap);
		DiamondTrap &operator=(const DiamondTrap &diamondtrap);
		~DiamondTrap(void);

		using ScavTrap::attack;

		void whoAmI(void);
};

#endif /* DIAMONDTRAP_HPP */
