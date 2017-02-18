#include "stdafx.h"
#include "filereader.h"


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

void FileReader::readfile(const char * input, Data* data)
{
	std::ifstream ifs(input, std::ifstream::in);
	std::string line;
	char delim = ' ';
	while (std::getline(ifs, line))
	{
		if (line.compare(0, 10, circleString) == 0)
		{
			std::vector<std::string> v;
			split(line, delim, v);
			data->m_iNumberOfTruePoints += stoi(v[3]);
			Circle circle;
			circle.radius = stof(v[7]);
			circle.center = Point(stof(v[9]), stof(v[10]));
			data->m_circles.push_back(circle);
		}
	}
	data->m_iNumberOfCirles = data->m_circles.size();
}

void FileReader::split(const std::string& s, char delim, std::vector<std::string>& v) {
	auto i = 0;
	auto pos = s.find(delim);
	while (pos != std::string::npos) {
		v.push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);

		if (pos == std::string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

