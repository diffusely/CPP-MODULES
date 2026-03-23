#pragma once

#include <iostream>
#include <string>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);


	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _static_value;
};
