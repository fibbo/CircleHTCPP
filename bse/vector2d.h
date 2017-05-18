#pragma once
#include "BaseObject.h"
#include <math.h>
namespace BSE {
    template<class T>
    class Vector2d : BaseObject
    {
    public:
		Vector2d() = default;
        Vector2d(T _x, T _y) : x(_x), y(_y) {}
		~Vector2d() = default;
        T x, y;

        virtual std::string to_string() override {
            return (std::to_string(x) + ", " + std::to_string(y));
        }

        T norm()
        {
            return sqrt(x*x + y*y);
        }
    };
}

