#pragma once
#include "vector2d.h"

namespace BSE
{
    std::string Vector2d::to_string()   {
        return (std::to_string(x) + ", " + std::to_string(y));
    }

}