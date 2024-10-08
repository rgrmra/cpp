/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:57:31 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/08 17:26:13 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Prompt.hpp"

#ifndef CONTACTS_LIMIT
#define CONTACTS_LIMIT 8
#endif /* CONTACTS_LIMIT */

#ifndef TABLE_FILL
#define TABLE_FILL ' '
#endif /* TABLE_FILL */

#ifndef TABLE_WIDTH
#define TABLE_WIDTH 10
#endif /* TABLE_WIDTH */

#define RED "\033[1;91m"
#define GREEN "\033[1;92m"
#define YELLOW "\033[1;93m"
#define COLOR "\033[1;94m"
#define LINE "\033[0;53m"
#define RESET "\033[0;m"

#define FNAME GREEN "First Name: " RESET
#define LNAME GREEN "Last Name: " RESET
#define NNAME GREEN "Nickname: " RESET
#define PHONE GREEN "Phone Number: " RESET
#define SECRET GREEN "Darkest Secret: " RESET

class PhoneBook
{
private:
	Contact _contacts[CONTACTS_LIMIT];
	size_t _index;
	Prompt _prompt;

	size_t _get_index();
	bool _is_valid_input(std::string &input, int (*function)(int));
	void _add_first_name();
	void _add_last_name();
	void _add_nickname();
	void _add_phone_number();
	void _add_darkest_secret();
	void _set_wfill(std::string str);
	bool _display_contacts();

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add_contact();
	void search_contact();
};

#endif /* PHONEBOOK_HPP */
