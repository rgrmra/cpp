/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:09:09 by rde-mour          #+#    #+#             */
/*   Updated: 2025/08/25 19:06:41 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(void) {

}

BitcoinExchange::BitcoinExchange(const std::string &database) {

	loadDatabase(database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {

	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {

	if (this == &rhs)
		return *this;

	_database = rhs._database;

	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {

}

std::string BitcoinExchange::trim(const std::string &str) {

	static const std::string set = " \t\n\v\f\r";

	size_t start = str.find_first_not_of(set);
	if (start == std::string::npos)
		return "";

	size_t end = str.find_last_not_of(set);
	return str.substr(start, end - start + 1);
}

std::pair<std::string, std::string> BitcoinExchange::separate(
		const std::string &line, const char &separator) {

		std::istringstream iss(line);
		std::string date;
		std::string value;

		std::getline(iss, date, separator);
		std::getline(iss, value);

		return std::make_pair(trim(date), trim(value));
}

std::string BitcoinExchange::getFileBuffer(const std::string &path) {
	
	std::ifstream file(path.c_str(), std::ios::binary);
	if (!file)
		throw std::runtime_error("failed to open file: " + path);

	std::ostringstream buffer;
	buffer << file.rdbuf();

	file.close();
	
	return buffer.str();
}

std::pair<bool, std::string> BitcoinExchange::isValidDate(
		const std::string &date) {

	struct std::tm tm_date = {};
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm_date))
		return std::make_pair(false, "bad input => " + date);

	std::time_t actual_time;
	std::time(&actual_time);

	std::time_t timestamp = std::mktime(&tm_date);
	if (timestamp == -1)
		return std::make_pair(false, "bad input => " + date);

	if (timestamp > actual_time)
			return std::make_pair(false, "I can't speculate => " + date);

	struct std::tm tm_date_new = *std::localtime(&timestamp);
	char buffer[11];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm_date_new);

	if (date != buffer)
		return std::make_pair(false, "bad input => " + date);

	return std::make_pair(true, "");
}

std::pair<bool, std::string> BitcoinExchange::isValidValue(const std::string &exchange) {

	if (exchange.find_first_not_of("0123456789.") != std::string::npos)
		return std::make_pair(false, "not a valid number.");

	double value = strtod(exchange.c_str(), NULL);

	if (value < 0)
		return std::make_pair(false, "not a positive number.");

	return std::make_pair(true, "");
}

void BitcoinExchange::loadDatabase(const std::string &database) {

	std::istringstream buffer(getFileBuffer(database));
	std::string line;

	std::getline(buffer, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid database header: " + line);

	while (std::getline(buffer, line)) {

		std::pair<std::string, std::string> tmp = separate(line, ',');

		std::pair<bool, std::string> status = isValidDate(tmp.first);
		if (!status.first)
			throw std::runtime_error("Invalid date: " + tmp.first);

		status = isValidValue(tmp.second);
		if (!status.first)
			throw std::runtime_error("Invalid value: " + tmp.second);

		_database[tmp.first] = strtod(tmp.second.c_str(), NULL);
	}
}

std::string BitcoinExchange::formatNumber(const double &number) {

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(6) << number;

	std::string value = oss.str();

	size_t pos = value.find('.');
	if (pos == std::string::npos)
		return value;

	while (value.size() > pos + 1 && value[value.size() - 1] == '0')
		value.erase(value.size() - 1, 1);

	if (value[value.size() - 1] == '.')
	    value.erase(value.size() - 1, 1);

	return value;
}

void BitcoinExchange::calculate(const std::string &date, const std::string &value) {

	if (_database.empty())
		throw std::runtime_error("no registers at database.");

	double dvalue = strtod(value.c_str(), NULL);
	if (dvalue > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	std::ostringstream oss;
	oss << date << " => " << value << " = ";

	std::map<std::string, double>::iterator it = _database.find(date);
	if (it != _database.end()) {
		std::cout << oss.str() << formatNumber(dvalue * it->second) << std::endl;
		return;
	}

	std::map<std::string, double>::iterator closest = _database.end();

	it = _database.begin();
	for (; it != _database.end() && it->first < date; it++)
		closest = it;

	if (closest != _database.end()) {
		std::cout << oss.str() << formatNumber(dvalue * closest->second) << std::endl;
		return;
	}

	std::cout << "Error: no registers before " << _database.begin()->first << "." << std::endl;
}

void BitcoinExchange::calculateExchange(const std::string &input) {

	std::istringstream buffer(getFileBuffer(input));
	std::string line;

	std::getline(buffer, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid input header: " + line);

	while (std::getline(buffer, line)) {

		std::pair<std::string, std::string> tmp = separate(line, '|');

		std::pair<bool, std::string> status = isValidDate(tmp.first);
		if (!status.first) {
			std::cout << "Error: " << status.second << std::endl;
			continue;
		}

		status = isValidValue(tmp.second);
		if (!status.first) {
			std::cout << "Error: " << status.second << std::endl;
			continue;
		}

		calculate(tmp.first, tmp.second);
	}
}
