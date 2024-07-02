/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/01 22:21:29 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact(void);
		void		setFirstName(std::string &firstName);
		std::string	getFirstName(void);
		void		setLastName(std::string &lastName);
		std::string	getLastName(void);
		void		setNickName(std::string &nickName);
		std::string	getNickName(void);
		void		setPhoneNumber(std::string &phoneNumber);
		std::string	getPhoneNumber(void);
		void		setDarkestSecret(std::string &darkestSecret);
		std::string	getDarkestSecret(void);
		~Contact(void);
};

#endif
