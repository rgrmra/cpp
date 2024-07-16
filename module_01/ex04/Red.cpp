/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:07:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/16 19:11:34 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "Red.hpp"
#include <cerrno>
#include <string>

Red::Red(std::string &text) : _text(text)
{

}

Red::~Red()
{

}

void	Red::replace(std::string from, std::string to)
{
	std::string	new_text;
	size_t		pos = 0;

	if (_text.empty() || from.empty())
		throw EINVAL;
	while (true)
	{
		pos = _text.find(from, pos);
		if (pos == std::string::npos)
			return ;
		new_text = _text.substr(0, pos);
		new_text.append(to);
		new_text.append(_text.substr(pos + from.length()));
		pos += to.length();
		_text = new_text;
	}
}
