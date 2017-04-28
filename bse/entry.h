#pragma once
#include "baseobject.h"
namespace BSE {
    class Entry : BaseObject
    {
    public:
        Entry() : start(-1), end(-1) {};
        ~Entry() {};
        Entry(int s, int e) : start(s), end(e) { count = end - start + 1; };
        int start, end;
        int count;

        // Inherited via BaseObject
        std::string BSE::Entry::to_string()
        {
            return "Entry start/end:\t" + std::to_string(start) + "/" + std::to_string(end);
        }

        Entry& operator=(const Entry& rhs) { this->start = rhs.start; this->end = rhs.end; this->count = rhs.count; return *this; }
    };
}

