#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "data.h"

class FileReader
{
public:
	FileReader();
	~FileReader();
	void readfile(const char* infile, Data* data);
	void split(const std::string&, char delim, std::vector<std::string>&);
	const char* circleString = "# * Circle";
};


