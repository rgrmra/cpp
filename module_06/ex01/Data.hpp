/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pessoa.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:44:29 by rde-mour          #+#    #+#             */
/*   Updated: 2024/12/14 20:10:42 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <ostream>
#include <string>

class Data {
	private:
		std::string _firstName;
		std::string _lastName;

	public:
		Data(void);
		Data(std::string firstName, std::string lastName);
		Data(const Data &src);
		Data &operator=(const Data &rhs);
		~Data(void);

		void setFirstName(std::string firstName);
		std::string getFirstName(void) const;

		void setLastName(std::string lastname);
		std::string getLastName(void) const;
};

std::ostream &operator<<(std::ostream &os, const Data &src);

#endif /* DATA_HPP */
