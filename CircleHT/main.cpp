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
    data.create_rings();
	CircleHT::findcircles("");
	data.print();
	std::getchar();
    return 0;
}

