#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

static bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static bool isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.size(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);

	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;

	if (day < 1 || day > maxDay)
		return (false);
	return (true);
}

static std::string trim(const std::string& s)
{
	size_t start = s.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t");
	return (s.substr(start, end - start + 1));
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
	std::ifstream file(databaseFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database file " + databaseFile);

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);

		if (!isValidDate(date))
			continue;

		_rates[date] = std::atof(rateStr.c_str());
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _rates(other._rates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::processInputFile(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (valueStr.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		char* end = NULL;
		double value = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0') {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		if (_rates.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
		if (it == _rates.end() || it->first != date) {
			if (it == _rates.begin()) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			--it;
		}

		std::cout << date << " => " << valueStr << " = " << (value * it->second) << std::endl;
	}
}
