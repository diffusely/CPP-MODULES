#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{
public:
	Span(unsigned int n);

	void addNumber(int value);
	
	int shortestSpan();
	int longestSpan();

private:
	unsigned int _n;
	std::vector<int> _arr;
	bool is_sorted;
};