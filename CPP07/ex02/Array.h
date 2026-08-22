#pragma once
#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const;
	~Array();

private:
	T* _array;
	unsigned int _size;
};

#include "Array.tpp"
