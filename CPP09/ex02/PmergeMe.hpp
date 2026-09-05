#pragma once

#include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void run(int argc, char** argv);

private:
	static std::vector<int> parseInput(int argc, char** argv);
};
