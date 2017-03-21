#pragma once
#include "BaseObject.h"
#include <math.h>
namespace BSE {
    template<class T>
    class Vector2d : BaseObject
    {
    public:
        Vector2d() {}
        Vector2d(T _x, T _y) : x(_x), y(_y) {}
        ~Vector2d() {};
        T x, y;

        std::string to_string() {
            return (std::to_string(x) + ", " + std::to_string(y));
        }

        float norm()
        {
            return sqrt(x*x + y*y);
        }
    };
}

