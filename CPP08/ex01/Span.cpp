#include "Span.h"

Span::Span(unsigned int n)
	: _n(n)
	, is_sorted(false)
{
	_arr.reserve(n);
}

void Span::addNumber(int value)
{
	if (_arr.size() >= _n)
		throw std::out_of_range("out of range!!");
	is_sorted = false;
	_arr.push_back(value);
}

int Span::shortestSpan()
{
	if (_arr.size() < 2)
		throw std::out_of_range("not enough elements to compute a span!!");
	if (!is_sorted)
		std::sort(_arr.begin(), _arr.end());
	
	int min = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < _arr.size() - 1; i++)
		min = std::min(min, std::abs(_arr[i] - _arr[i + 1]));

	is_sorted = true;
	return min;
}

int Span::longestSpan()
{
	if (_arr.size() < 2)
		throw std::out_of_range("not enough elements to compute a span!!");

	int minVal = *std::min_element(_arr.begin(), _arr.end());
	int maxVal = *std::max_element(_arr.begin(), _arr.end());

	return (maxVal - minVal);
}
