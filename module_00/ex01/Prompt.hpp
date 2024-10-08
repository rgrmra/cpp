/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:10:21 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/08 17:25:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
#define PROMPT_H

#include <string>

class Prompt
{
public:
	Prompt();
	~Prompt();

	std::string	get_line(std::string str);

private:
	bool _is_valid_input(std::string str);
};

#endif /* PROMPT_H */
