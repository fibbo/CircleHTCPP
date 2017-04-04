#pragma once
#include <string>

namespace BSE {
    class BaseObject
    {
    public:
        virtual std::string to_string() = 0;
    };
}