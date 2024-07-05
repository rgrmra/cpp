/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:57:31 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/05 19:24:11 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include "Prompt.hpp"

# ifndef CONTACTS_LIMIT
#  define CONTACTS_LIMIT 8
# endif

# define FNAME	"First Name :"
# define LNAME	"Last Name :"
# define NNAME	"Nickname :"
# define PHONE	"Phone Number: "
# define SECRET	"Darkest Secret: "

class	PhoneBook
{
	private:
		Contact _contacts[CONTACTS_LIMIT];
		int		_index;
		Prompt	_prompt;

		int		get_index();
		void	add_first_name();
		void	add_last_name();
		void	add_nickname();
		void	add_phone_number();
		void	add_darkest_secret();
		void	display_contacts();

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact();
		void	search_contact();
};

#endif
