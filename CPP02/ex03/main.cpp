#include "Point.h"

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

int main(void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	{
	Point p1(6, 0);
	Point p2(5, 5);
	Point p3(0, 0);
	Point p4(2.5, 2.5);
	Point p5(5, 1);

	std::cout << "Point p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p4 is " << (bsp(a, b, c, p4) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p5 is " << (bsp(a, b, c, p5) ? "inside" : "outside") << " the triangle" << std::endl;
	}

	{
	std::cout << "-------------------------------------" << std::endl;
	Point p1(8, 0);
	Point p2(2, 5);
	Point p3(0, 3);
	Point p4(3.5, 3.5);
	Point p5(5, 5);

	std::cout << "Point p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p4 is " << (bsp(a, b, c, p4) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "Point p5 is " << (bsp(a, b, c, p5) ? "inside" : "outside") << " the triangle" << std::endl;
	}

	return (0);
}