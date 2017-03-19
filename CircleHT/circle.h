#pragma once
#include <iostream>
#include "point.h"

class Circle
{
public:
	Circle() {}
	Circle(BSE::Point<float> c, float r) : center(c), radius(r) {}
	~Circle() {}
	BSE::Point<float> center;
	float radius;

	void print();
};

