/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:02:34 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/15 23:00:14 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	
	private:
		std::map<std::string, double> _database;

		std::string trim(const std::string &str);
		std::pair<std::string, std::string> separate(const std::string &line, const char &separator);

		std::string getFileBuffer(const std::string &path);

		std::pair<bool, std::string> isValidDate(const std::string &date);
		std::pair<bool, std::string> isValidValue(const std::string &exchange);

		void calculate(const std::string &date, const std::string &value);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &database);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange(void);

		void loadDatabase(const std::string &database);
		void calculateExchange(const std::string &input);

};

#endif /* BITCOINEXCHANGE_HPP */
