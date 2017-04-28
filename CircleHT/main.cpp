// CircleHT.cpp : Defines the entry point for the console application.
//

#include "filereader.h"
#include "histogram.h"
#include "binnableObject.h"

int main(int argc, char* argv[])
{
	FileReader fr;
	Data data;
	fr.readfile("..\\data\\simple.txt", &data);
	data.create_triplets();
    data.create_rings();
    data.sort_rings();
    BSE::Histogram<float> h(0.07f, 0.170f, 0.010f, data.m_rings);
    h.print();
	data.print();
	std::getchar();
    return 0;
}

