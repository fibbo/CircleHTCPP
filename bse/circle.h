#pragma once
#include <iostream>
#include "point.h"

namespace BSE
{
    template<class T>
    class Circle : BaseObject
    {
    public:
        Circle() = default;
        Circle(BSE::Point<T> c, T r) : center(c), radius(r) {}
        ~Circle() = default;
        BSE::Point<T> center;
        T radius;

        void print()
        {
            std::cout << "Circle:\t" << "Center: (" << center.x << ", " << center.y << ")" << "\t" << "Radius: " << radius << std::endl;
        }

        virtual std::string to_string() override
        {
            return std::string();
        }

    };

}
