#pragma once

#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
public:
	Fixed();
	Fixed(const int& value);
	Fixed(const float& value);
	~Fixed();

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	float toInt(void) const;

private:
	int _value;
	static const int _static_value;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);