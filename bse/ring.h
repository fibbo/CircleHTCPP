#pragma once
#include "point.h"
#include "baseobject.h"

namespace BSE
{
    template<class T>
    class Ring : BaseObject
    {
    public:
        Ring(BSE::Point<T> c, T r)
        {
            m_center = c;
            m_radius = r;
        }
        ~Ring() {}
        BSE::Point<T> m_center;
        T m_radius;


        // Inherited via BaseObject
        std::string to_string() override
        {
            return std::string();
        }


    };
}
