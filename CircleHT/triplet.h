#pragma once
#include "point.h"

class Triplet
{
public:
	Triplet();
    Triplet(BSE::Point<float>* p0, BSE::Point<float>* p1, BSE::Point<float>* p2)
    {
        points[0] = p0;
        points[1] = p1;
        points[2] = p2;
    }
	~Triplet();
	BSE::Point<float>* points[3];
};

