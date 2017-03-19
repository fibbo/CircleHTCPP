#pragma once
#include <iostream>
#include "point.h"
class Circle
{
public:
	Circle() {}
	Circle(BSE::Point c, float r) : center(c), radius(r) {}
	~Circle() {}
	BSE::Point center;
	float radius;

	void print();
};

