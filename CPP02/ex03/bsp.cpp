#include "Point.h"

float t_area(const Point& a, const Point& b, const Point& c)
{
	return (std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + \
		b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + \
		c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0));
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	Fixed	total = t_area(a, b, c);
	Fixed	area1 = t_area(point, b, c);
	Fixed	area2 = t_area(a, point, c);
	Fixed	area3 = t_area(a, b, point);
	return (total == area1 + area2 + area3);
}