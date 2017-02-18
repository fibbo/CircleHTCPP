#pragma once
#include <iostream>
class Point
{
public:
	Point() {}
	Point(float _x, float _y) : x(_x), y(_y) {}
	void print();

	float x, y;
};