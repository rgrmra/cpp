/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:56:41 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/16 19:01:03 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Red
{
	private:
		std::string	&_text;

	public:
		Red(std::string &text);
		~Red();
		void		replace(std::string from, std::string to);
};
