/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:39:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/31 14:54:16 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
  ClapTrap claptrap("Marvin");
  claptrap.status();

  std::cout << "Messages tests" << std::endl;
  claptrap.attack("You");
  claptrap.status();
  claptrap.set_attack_damage(2);
  claptrap.status();
  claptrap.attack("");
  claptrap.status();
  claptrap.takeDamage(1);
  claptrap.status();
  claptrap.beRepaired(1);
  claptrap.status();

  std::cout << std::endl;
  std::cout << "Health Points tests" << std::endl;

  claptrap.takeDamage(1);
  claptrap.status();
  claptrap.beRepaired(2);
  claptrap.status();
  claptrap.takeDamage(10);
  claptrap.status();
  claptrap.takeDamage(1);
  claptrap.status();

  std::cout << std::endl;
  std::cout << "Energy tests" << std::endl;

  /* setuping for energy tests */
  claptrap.set_energy_points(0);
  claptrap.status();
  claptrap.set_hit_points(10);
  claptrap.status();

  claptrap.attack("You again");
  claptrap.status();
  claptrap.beRepaired(1);
  claptrap.status();
  claptrap.attack("A ghost");
  claptrap.status();

  return EXIT_SUCCESS;
}
