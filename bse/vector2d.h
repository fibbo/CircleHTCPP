#pragma once
#include "BaseObject.h"
namespace BSE {
    class Vector2d : BaseObject
    {
    public:
        Vector2d() {}
        Vector2d(float _x, float _y) : x(_x), y(_y) {}
        ~Vector2d() {};
        float x, y;

        std::string to_string() override;

    };
}

