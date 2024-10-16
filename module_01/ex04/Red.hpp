/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:56:41 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/14 21:05:31 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_HPP
#define RED_HPP

#include <string>

class Red
{
	private:
		std::string &_text;

	public:
		Red(std::string &text);
		~Red(void);

		void replace(std::string from, std::string to);
};

#endif /* RED_HPP */
