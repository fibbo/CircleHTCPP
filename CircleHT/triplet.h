#pragma once
#include "point.h"

class Triplet
{
public:
	Triplet();
    Triplet(BSE::Point* p0, BSE::Point* p1, BSE::Point* p2)
    {
        points[0] = p0;
        points[1] = p1;
        points[2] = p2;
    }
	~Triplet();
	BSE::Point* points[3];
};

