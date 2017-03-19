#pragma once
#include <string>

namespace BSE {
    class BaseObject
    {
        virtual std::string to_string() = 0;
    };
}