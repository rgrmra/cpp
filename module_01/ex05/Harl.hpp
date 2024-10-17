/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:08:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/17 14:24:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define PURPLE "\033[0;95m"
#define RESET "\033[0;m"

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
	
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void invalid(void);

		typedef void (Harl::*method)();
  		method methods[5];
};

#endif /* HARL_HPP */
