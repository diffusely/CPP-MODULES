#include "Fixed.h"

const int Fixed::_static_value = 8;

Fixed::Fixed() : _value(0)
{}

Fixed::Fixed(const int &value) : _value(value << _static_value)
{}

Fixed::Fixed(const float &value) : _value(roundf(value * (1 << _static_value)))
{}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &other)
{
	_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _static_value));
}

float Fixed::toInt(void) const
{
	return (_value >> _static_value);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (!(_value == other._value));
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed &Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(toFloat());
	++_value;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(toFloat());
	--_value;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
