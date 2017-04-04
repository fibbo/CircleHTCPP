#pragma once
#include "baseobject.h"
#include "entry.h"
#include "binnableObject.h"
#include <vector>
#include <iostream>

namespace BSE {
    class Histogram
    {
    public:
        template<typename T> Histogram(float start, float end, float bin_size, std::vector<T>* data);


        std::vector<Entry> bins;
        void print()
        {
            for (auto bin : bins)
            {
                std::cout << bin.to_string() + "\n";
            }
        }
    };

    template<typename T> Histogram::Histogram(float start, float end, float bin_size, std::vector<T>* data)
    {
        int nBins = (int)ceil((end - start) / bin_size);
        bins.resize(nBins);
        int lastBin = 0;
        int currentBin = 0;
        float curMaxValue = (currentBin + 1)*bin_size + start;
        for (int i = 0; i < data->size(); i++)
        {
            auto binObject = data->at(i)->getBinnableObject();
            if ( binObject < curMaxValue)
            {
                std::cout << data->at(i)->getBinnableObject() << std::endl;
                ++currentBin;
            }
            else
            {
                std::cout << data->at(i)->getBinnableObject() << std::endl;
                Entry e(lastBin, currentBin);
                bins.push_back(e);
                lastBin = currentBin;
                ++currentBin;
                curMaxValue = (currentBin + 1)*bin_size;
            }
        }
    }
}
