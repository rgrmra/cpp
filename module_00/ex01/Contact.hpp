/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:01 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/08 17:11:18 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

public:
	Contact(void);
	~Contact(void);

	void set_first_name(const std::string& first_name);
	std::string get_first_name();
	void set_last_name(const std::string& last_name);
	std::string get_last_name();
	void set_nickname(const std::string& nickname);
	std::string get_nickname();
	void set_phone_number(const std::string& phone_number);
	std::string get_phone_number();
	void set_darkest_secret(const std::string& darkest_secret);
	std::string get_darkest_secret();
};

#endif /* CONTACT_HPP */
