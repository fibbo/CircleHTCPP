#pragma once
#include "point.h"
#include "exceptions.h"

namespace BSE
{
    template<class T>
    class Triplet : BaseObject
    {
    public:
        Triplet() = default;
        Triplet(Point<T>* p0, Point<T>* p1, Point<T>* p2)
        {
            points[0] = p0;
            points[1] = p1;
            points[2] = p2;
        }
        ~Triplet() = default;
        Point<T>* points[3];

        std::string to_string() override
        {
            throw NotImplementedException();
        }
    };

}
