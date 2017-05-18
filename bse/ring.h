#pragma once
#include "point.h"
#include "baseobject.h"
#include "binnableObject.h"

namespace BSE
{
    template<class T>
    class Ring : BaseObject, BinnableObject<T>
    {
    public:
        Ring(BSE::Point<T> c, T r)
        {
            m_center = c;
            m_radius = r;
        }
        ~Ring() = default;
        BSE::Point<T> m_center;
        T m_radius;


        // Inherited via BaseObject
        virtual std::string to_string() override
        {
            return std::string();
        }

        T getBinnableObject()
        {
            return m_radius;
        }

        friend bool operator<(const Ring& lhs, const Ring& rhs) { return lhs.m_radius < rhs.m_radius; }
    };
}
