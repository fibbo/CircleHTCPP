#pragma once
#include "baseobject.h"
#include "vector2d.h"

namespace BSE
{
    template<class T>
    class Point : BaseObject
    {
    public:
		Point() = default;
		~Point() = default;
        Point(T _x, T _y) : x(_x), y(_y) {}

        virtual std::string to_string() override
        {
            return (std::to_string(x) + ", " + std::to_string(y));
        }

        T x, y;

        friend bool operator<(const Point &lhs, const Point &rhs) { return (lhs.x*lhs.x + lhs.y*lhs.y) < (rhs.x*rhs.x + rhs.y*rhs.y); }
        friend Vector2d<T> operator-(const Point &lhs, const Point &rhs) { return Vector2d<T>(lhs.x - rhs.x, lhs.y - rhs.y); }
        Point<T>& operator/=(const T &div) {  this->x /= div; this->y /= div; return *this; }
    };
}
