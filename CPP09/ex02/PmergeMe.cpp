#include "PmergeMe.hpp"
#include <deque>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

static bool isValidPositiveInt(const std::string& s, long& outValue)
{
	if (s.empty())
		return (false);

	size_t i = 0;
	if (s[i] == '+')
		i++;
	if (i == s.size())
		return (false);

	for (; i < s.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	}

	char* end = NULL;
	long val = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0' || val < 0 || val > INT_MAX)
		return (false);

	outValue = val;
	return (true);
}

std::vector<int> PmergeMe::parseInput(int argc, char** argv)
{
	std::vector<int> result;

	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);
		long value = 0;

		if (!isValidPositiveInt(token, value))
			throw std::runtime_error("Error: bad input => " + token);
		result.push_back(static_cast<int>(value));
	}

	if (result.empty())
		throw std::runtime_error("Error: no input");

	return (result);
}

template<typename Container>
static Container mergeInsertionSort(Container vec)
{
	typedef typename Container::value_type T;

	if (vec.size() <= 1)
		return (vec);

	bool hasStraggler = (vec.size() % 2 != 0);
	T straggler = T();
	if (hasStraggler)
	{
		straggler = vec.back();
		vec.pop_back();
	}

	Container mainChain;

	if (!vec.empty())
	{
		Container winners;
		Container losers;

		for (size_t i = 0; i < vec.size(); i += 2)
		{
			T a = vec[i];
			T b = vec[i + 1];
			if (a > b)
			{
				winners.push_back(a);
				losers.push_back(b);
			}
			else
			{
				winners.push_back(b);
				losers.push_back(a);
			}
		}

		std::map<T, std::vector<T> > companions;
		typename Container::iterator wIt = winners.begin();
		typename Container::iterator lIt = losers.begin();
		for (; wIt != winners.end(); ++wIt, ++lIt)
			companions[*wIt].push_back(*lIt);

		mainChain = mergeInsertionSort(winners);

		std::vector<T> orderedLosers;
		for (typename Container::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
		{
			std::vector<T>& bucket = companions[*it];
			orderedLosers.push_back(bucket.back());
			bucket.pop_back();
		}

		mainChain.insert(mainChain.begin(), orderedLosers[0]);

		for (size_t i = 1; i < orderedLosers.size(); i++)
		{
			typename Container::iterator pos =
				std::lower_bound(mainChain.begin(), mainChain.end(), orderedLosers[i]);
			mainChain.insert(pos, orderedLosers[i]);
		}
	}

	if (hasStraggler)
	{
		typename Container::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	return (mainChain);
}

static double nowMicroseconds()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec));
}

template<typename Container>
static void printContainer(const Container& c)
{
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::run(int argc, char** argv)
{
	std::vector<int> input = parseInput(argc, argv);

	std::cout << "Before: ";
	printContainer(input);

	std::vector<int> vecCopy(input.begin(), input.end());
	std::deque<int> deqCopy(input.begin(), input.end());

	double startVec = nowMicroseconds();
	std::vector<int> sortedVec = mergeInsertionSort(vecCopy);
	double endVec = nowMicroseconds();

	double startDeq = nowMicroseconds();
	std::deque<int> sortedDeq = mergeInsertionSort(deqCopy);
	double endDeq = nowMicroseconds();

	std::cout << "After: ";
	printContainer(sortedVec);

	std::cout << "Time to process a range of " << input.size()
		<< " elements with std::vector : " << (endVec - startVec) << " us" << std::endl;
	std::cout << "Time to process a range of " << input.size()
		<< " elements with std::deque : " << (endDeq - startDeq) << " us" << std::endl;

	(void)sortedDeq;
}
