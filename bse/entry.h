#pragma once
#include "baseobject.h"
namespace BSE {
    class Entry : BaseObject
    {
    public:
        Entry() : start(-1), end(-1) {};
        ~Entry() {};
        Entry(int s, int e) : start(s), end(e) {};
        int start, end;

        // Inherited via BaseObject
        std::string BSE::Entry::to_string()
        {
            return "Entry start/end:\t" + std::to_string(start) + "/" + std::to_string(end);
        }
    };
}

