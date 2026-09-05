#pragma once

#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const std::string& databaseFile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processInputFile(const std::string& inputFile) const;

private:
	std::map<std::string, double> _rates;
};
