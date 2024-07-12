/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:57:31 by rde-mour          #+#    #+#             */
/*   Updated: 2024/07/12 15:15:32 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "Prompt.hpp"

# ifndef CONTACTS_LIMIT
#  define CONTACTS_LIMIT 8
# endif

# define RED	"\033[1;91m"
# define GREEN	"\033[1;92m"
# define YELLOW	"\033[1;93m"
# define COLOR	"\033[1;94m"
# define HEADER	"\033[0;104m"
# define LINE	"\033[0;53m"
# define RESET	"\033[0;m"

# define FNAME	GREEN "First Name: " RESET
# define LNAME	GREEN "Last Name: " RESET
# define NNAME	GREEN "Nickname: " RESET
# define PHONE	GREEN "Phone Number: " RESET
# define SECRET	GREEN "Darkest Secret: " RESET

class	PhoneBook
{
	private:
		Contact _contacts[CONTACTS_LIMIT];
		int		_index;
		Prompt	_prompt;

		int		_getIndex();
		bool	_invalidInput(std::string &input, int (*function)(int));
		void	_addFirstName();
		void	_addLastName();
		void	_addNickname();
		void	_addPhoneNumber();
		void	_addDarkestSecret();
		void	_setWFill(unsigned long width, char fill, std::string str);
		bool	_displayContacts();

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact();
		void	searchContact();
};

#endif
