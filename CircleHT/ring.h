#pragma once
#include "point.h"
class Ring
{
public:
    Ring() {}
    Ring(BSE::Point c, float r);
    ~Ring() {}
    BSE::Point m_center;
    float m_radius;
};

