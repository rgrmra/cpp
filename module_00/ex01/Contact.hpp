/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/12 14:57:56 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

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
		~Contact(void);
		void		setFirstName(const std::string &first_name);
		std::string	getFirstName(void);
		void		setLastName(const std::string &last_name);
		std::string	getLastName(void);
		void		setNickname(const std::string &nickname);
		std::string	getNickname(void);
		void		setPhoneNumber(const std::string &phone_number);
		std::string	getPhoneNumber(void);
		void		setDarkestSecret(const std::string &darkest_secret);
		std::string	getDarkestSecret(void);
};

#endif
