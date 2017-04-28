#pragma once
#include "baseobject.h"
#include "entry.h"
#include "binnableObject.h"
#include <vector>
#include <iostream>

namespace BSE {
    template<typename T>
    class Histogram
    {
    public:
        template<typename V> Histogram(T start, T end, T bin_size, std::vector<V>* data)
        {
            m_start = start;
            m_end = end;
            m_bin_size = bin_size;

            int nBins = (int)ceil((end - start) / bin_size);
            m_bins.resize(nBins);
            int firstEntryIndex = 0;
            int lastEntryIndex = 0;
            int currentBin = 0;
            T curMaxValue = (currentBin + 1)*bin_size + start;
            int index = 0;
            for (int i = 0; i < m_bins.size(); i++)
            {
                while (index < data->size() && data->at(index).getBinnableObject() < curMaxValue)
                    ++index;

                Entry e(firstEntryIndex, index);
                curMaxValue += bin_size;
                firstEntryIndex = index;
                m_bins.at(i) = e;
            }
        }


        std::vector<Entry> m_bins;
        T m_start;
        T m_end;
        T m_bin_size;

        void print()
        {
            for (auto e : m_bins)
            {
                std::cout << e.to_string() + "\n";
            }
        }
    };


}
