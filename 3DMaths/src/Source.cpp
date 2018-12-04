#include <iostream>
#include <math.h>

class Vector
{
public :
	float x, y;

public:
	//Constructor
	Vector()
	{

	}

	Vector(float X, float Y)
	{
		x = X;
		y = Y;
	}

	float length() const;
	float sqrLength() const;

	//Vector scaling by an given scalar number
	Vector operator * (float number) const;
	Vector operator / (float number) const;

	Vector normalized() const;

	Vector operator + (const Vector& v) const;
	Vector operator - (const Vector& v) const;
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

//Normalizing a vector by dividing the vector with its magnitude
Vector Vector::normalized() const
{
	Vector normalized;
	normalized = (*this) / length();
	return normalized;
}

//Adding 2 vectors
Vector Vector ::operator+(const Vector& v) const
{
	Vector r;
	r.x = x + v.x;
	r.y = y + v.y;
	return r;
}

//Substracting 2 vectors
Vector Vector ::operator-(const Vector& v) const
{
	return Vector(x - v.x, y - v.y);
}

//Comparing the directions of 2 vectors to find a backstab;
float dotProduct(const Vector& a, const Vector& b)
{
	return (a.x * b.x + a.y * b.y);
}

int main()
{
	Vector r(0, 3);
	Vector b(0, 2);

	Vector rn = r.normalized();
	Vector bn = b.normalized();

	if ((dotProduct(rn, bn)) < -0.5)
	{
		std::cout << " You got backstabed" << std::endl;
	}
	else
		std::cout << "failed" << std::endl;

	//std::cout << "(" << p1.x << ", " << p1.y << ")" << std::endl;
	std::cin.get();
}
