#include "point.h"

void Point::print()
{
	std::cout << "x: " << x << "\t y: " << y << std::endl;
}

std::string Point::to_string()
{
    return (std::to_string(x) + ", " + std::to_string(y));
}

