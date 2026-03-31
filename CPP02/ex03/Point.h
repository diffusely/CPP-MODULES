#pragma once

#include "Fixed.h"

class Point
{
public:

	Point();
	Point(const float&, const float&);
	Point(const Point&);
	Point& operator=(const Point&);
	~Point();

	const Fixed getX() const;
	const Fixed getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};