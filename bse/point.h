#pragma once
#include "baseobject.h"
#include "vector2d.h"

namespace BSE
{
    class Point : BaseObject
    {
    public:
        Point() {}
        ~Point() {}
        Point(float _x, float _y) : x(_x), y(_y) {}

        std::string to_string();

        float x, y;

        friend bool operator<(const Point &lhs, const Point &rhs) { return (lhs.x*lhs.x + lhs.y*lhs.y) < (rhs.x*rhs.x + rhs.y*rhs.y); }
        friend Vector2d operator-(const Point &lhs, const Point &rhs) { return Vector2d(lhs.x - rhs.x, lhs.y - rhs.y); }
    };
}
