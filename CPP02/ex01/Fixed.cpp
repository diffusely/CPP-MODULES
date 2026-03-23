#include "Fixed.h"

const int Fixed::_static_value = 8;

Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called\n";
}


Fixed::Fixed(const int& value)
	: _value(value << _static_value)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float& value)
	: _value(roundf(value * (1 << _static_value)))
{
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_value = other._value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}