#pragma once 
#include <cstddef>

template<typename T, typename F>
void iter(T* array, const std::size_t& length, F fo)
{
	for(std::size_t i = 0; i < length; i++)
		fo(array[i]);

}