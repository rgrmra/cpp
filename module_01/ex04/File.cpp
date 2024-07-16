/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:29:00 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/16 18:54:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <fstream>
#include <string>

File::File(std::string filename) : _infile(filename)
{
	_outfile = _infile + ".replace";
}

File::~File(void)
{

}

std::string	File::read()
{
	std::ifstream	file(_infile.c_str());
	std::string		text;
	std::string		line;

	if (!file)
		throw ENOENT;
	while (std::getline(file, line))
		text += line + "\n";
	file.close();
	return text;
}

void	File::write(std::string text)
{
	std::ofstream	file(_outfile.c_str());

	if (!file)
		throw ENOENT;
	file << text;
	file.close();
}
