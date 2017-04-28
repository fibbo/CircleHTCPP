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
		m_circles = new std::vector<BSE::Circle<float>>();
		m_rings = new std::vector<BSE::Ring<float>>();
    }
	~Data();

	int m_iNumberOfCirles;
	int m_iNumberOfTruePoints;
	std::vector<BSE::Circle<float>>* m_circles;
	std::vector<BSE::Point<float>*>* m_points;
	std::vector<BSE::Triplet<float>*>* m_triplets;
    std::vector<BSE::Ring<float>>* m_rings;

	void print(bool printCircles=false);

    // Create all possible 3-tuple that can be made with the available points
	void create_triplets();
    
    //Calculates the rings that are defined by the three points of each triplet
    void create_rings();

    //Sort the rings according to their radius
    void sort_rings();
};

