/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:41:11 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/16 19:01:52 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include "Red.hpp"
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	status = EXIT_SUCCESS;

	try
	{
		if (argc != 4)
			throw EPERM;

		File file(argv[1]);
		std::string text = file.read();

		Red red(text);
		red.replace(argv[2], argv[3]);

		file.write(text);
	}
	catch (int exception)
	{
		if (exception == ENOENT)
			std::cout << "red: No such file" << std::endl;
		else if (exception == EINVAL)
			std::cout << "red: Invalid argument" << std::endl;
		else
			std::cout << "Usage: red <filename> <from> <to>" << std::endl;
		status = exception;
	}
	return status;
}
