/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:57:31 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/02 20:00:07 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# ifndef CONTACTS_LIMIT
#  define CONTACTS_LIMIT 8
# endif

class	PhoneBook
{
	private:
		Contact _contacts[CONTACTS_LIMIT];
		short	_index;

		void	add_first_name();
		void	add_last_name();
		void	add_nickname();
		void	add_phone_number();
		void	add_darkest_secret();

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact();
		void	search_contact();
};

#endif
