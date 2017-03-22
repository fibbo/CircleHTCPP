// CircleHT.cpp : Defines the entry point for the console application.
//

#include "circleht.h"
#include "filereader.h"

int main(int argc, char* argv[])
{
	FileReader fr;
	Data data;
	fr.readfile("C:\\Users\\phi\\Documents\\GitHub\\CircleHoughTransform\\data\\forpresentation.txt", &data);
	data.create_triplets();
	CircleHT::findcircles("");
    data.create_rings();
    data.sort_rings();
	data.print();
	std::getchar();
    return 0;
}

