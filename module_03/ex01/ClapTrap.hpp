/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:49:21 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/31 19:13:42 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &claptrap);
		~ClapTrap(void);

		void set_name(std::string name);
		std::string get_name(void) const;
		void set_hit_points(unsigned int hit_points);
		unsigned int get_hit_points(void) const;
		bool has_hit_points(void) const;
		void set_energy_points(unsigned int energy_points);
		unsigned int get_energy_points(void) const;
		bool has_energy_points(void) const;
		void set_attack_damage(unsigned int attack_damage);
		unsigned int get_attack_damage(void) const;
		bool has_attack_damage(void) const;

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_HPP */
