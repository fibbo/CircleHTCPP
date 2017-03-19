// CircleHT_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "point.h"
#include "vector2d.h"

int main()
{
    BSE::Point x1(1., 1.);
    BSE::Point x2(3., 4.);

    BSE::Vector2d v = x2 - x1;
    std::cout << v.to_string() << std::endl;
    std::getchar();
    return 0;
}

