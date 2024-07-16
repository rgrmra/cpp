/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:18:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/16 19:04:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILE_H
# define FILE_H

# include <string>

class File
{
	private:
		std::string	_infile;
		std::string	_outfile;

	public:
		File(std::string filename);
		~File(void);
		std::string	read(void);
		void		write(std::string text);
};

#endif
