#include <iostream>
#include <math.h>

class Vector
{
public :
	float x, y;

public:
	
};

class Point
{
public:
	float x, y;

public:
	Point operator + (Vector v) const;
};


// Adding speed to a point p
Point Point::operator + (Vector v) const
{
	Point p2;
	p2.x = x + v.x;
	p2.y = y + v.y;
	return p2;
}

// Vector from p2 -> p1 is found by substracting position p1 - p2
Vector operator - (Point p1, Point p2)
{
	Vector v;
	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	return v;
}


int main()
{
	Point p;
	p.x = 1;
	p.y = 1;

	Vector v;
	v.x = 2;
	v.y = 2;

	Point p1 = p + v;

	std::cout << "(" << p1.x << ", " << p1.y << ")" << std::endl;
	std::cin.get();
}
