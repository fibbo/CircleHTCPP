#pragma once
#include <vector>
#include "circle.h"
#include "triplet.h"
#include "ring.h"
#include <iostream>
#include <algorithm>
#include <math.h>

class Data
{
public:
    Data()
    {
        m_triplets = new std::vector<BSE::Triplet<float> *>();
        m_points = new std::vector<BSE::Point<float> *>();
    }
	~Data();

	int m_iNumberOfCirles;
	int m_iNumberOfTruePoints;
	std::vector<BSE::Circle<float>> m_circles;
	std::vector<BSE::Point<float>*>* m_points;
	std::vector<BSE::Triplet<float>*>* m_triplets;
    std::vector<BSE::Ring<float>*> m_rings;

	static const int TRIPLET = 3;

	void print(bool printCircles=false);
	void create_triplets();
    void create_rings();
    void sort_rings();
};

