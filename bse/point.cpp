#include "point.h"
namespace BSE
{
    std::string Point::to_string()
    {
        return (std::to_string(x) + ", " + std::to_string(y));
    }

}
