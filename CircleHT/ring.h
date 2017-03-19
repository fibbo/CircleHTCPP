#pragma once
#include "point.h"

class Ring
{
public:
    Ring() {}
    Ring(BSE::Point<float> c, float r);
    ~Ring() {}
    BSE::Point<float> m_center;
    float m_radius;
};

