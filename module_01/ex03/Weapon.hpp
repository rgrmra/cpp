/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:53:25 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 20:53:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(const std::string type);
		~Weapon(void);

		void setType(const std::string type);
		const std::string &getType();
};

#endif /* WEAPON_HPP */
