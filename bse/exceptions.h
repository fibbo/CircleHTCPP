#pragma once
#include <stdexcept>

namespace BSE
{
    class NotImplementedException : public std::logic_error
    {
    public:
        NotImplementedException() : std::logic_error{ "Function not yet implemented." } {}
        virtual char const* what() { return "Function not yet implemented."; }
    };
}
