#pragma once
#include <iostream>
#include <string>
#include "stdafx.h"

class Point : BaseObject
{
public:
	Point() {}
	Point(float _x, float _y) : x(_x), y(_y) {}
	void print();
	std::string to_string();

	float x, y;

    friend bool operator<(const Point &lhs, const Point &rhs) { return (lhs.x*lhs.x + lhs.y*lhs.y) < (rhs.x*rhs.x + rhs.y*rhs.y); }
};