#include <iostream>
#include <math.h>

class Vector
{
public :
	float x, y;

public:
	
	float length() const;
	float sqrLength() const;

	//Vector scaling by an given scalar number
	Vector operator * (float number) const;
	Vector operator / (float number) const;

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

// Finding magnitude of a vector
float Vector::length() const
{
	 return(sqrt(x*x + y*y));
}

// Finding length of 2 vectors for comparison
float Vector::sqrLength() const
{
	return(x*x + y*y);
}

// Scaling the vector with a scalar number
Vector Vector::operator * (float n) const
{
	Vector v;
	v.x = x * n;
	v.y = y * n;
	return v;
}


// Scaling the vector with a scalar number
Vector Vector::operator / (float n) const
{
	Vector v;
	v.x = x / n;
	v.y = y / n;
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
