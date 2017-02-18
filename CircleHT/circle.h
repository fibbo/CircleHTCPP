#pragma once
#include <iostream>
#include "point.h"
class Circle
{
public:
	Circle() {}
	Circle(Point c, float r) : center(c), radius(r) {}
	~Circle() {}
	Point center;
	float radius;

	void print();
};

