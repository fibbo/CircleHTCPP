#pragma once
#include <vector>
#include "point.h"
#include "circle.h"
#include "triplet.h"
#include <iostream>

class Data
{
public:
	Data();
	~Data();

	int m_iNumberOfCirles;
	int m_iNumberOfTruePoints;
	std::vector<Circle> m_circles;
	std::vector<Point> m_points;
	std::vector<Triplet> m_triplets;

	void print(bool printCircles=false);
};

