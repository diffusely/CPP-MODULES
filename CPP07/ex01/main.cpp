#include "iter.h"
#include <iostream>
#include <string>

template<typename T>
void print(const T& x)
{
	std::cout << x << " ";
}

void doubleInt(int& x)
{
	x *= 2;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::size_t arrLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "int array: ";
	iter(arr, arrLen, print<int>);
	std::cout << std::endl;

	iter(arr, arrLen, doubleInt);
	std::cout << "after doubleInt: ";
	iter(arr, arrLen, print<int>);
	std::cout << std::endl;

	std::string words[] = {"foo", "bar", "baz"};
	std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "string array: ";
	iter(words, wordsLen, print<std::string>);
	std::cout << std::endl;

	const int constArr[] = {10, 20, 30};
	std::size_t constArrLen = sizeof(constArr) / sizeof(constArr[0]);

	std::cout << "const int array: ";
	iter(constArr, constArrLen, print<int>);
	std::cout << std::endl;

	return (0);
}
