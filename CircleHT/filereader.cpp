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
	const char delim = ' ';
    while (std::getline(ifs, line))
    {
        if (line.compare(0, 10, circleString) == 0)
        {
            std::vector<std::string> v;
            split(line, delim, v);
            data->m_iNumberOfTruePoints += stoi(v[3]);
            BSE::Circle<float> circle;
            circle.radius = stof(v[7]);
            circle.center = BSE::Point<float>(stof(v[9]), stof(v[10]));
            data->m_circles->push_back(circle);
        }
        else if (line.compare(0, 1, "#"))
        {
            std::vector<std::string> v;
            split(line, delim, v);
            BSE::Point<float>* p = new BSE::Point<float>(stof(v[0]), stof(v[1]));
            data->m_points->push_back(p);
        }
	}
	data->m_iNumberOfCirles = (int)data->m_circles->size();
}

void FileReader::split(const std::string& s, char delim, std::vector<std::string>& v) {
	size_t i = 0;
	auto pos = s.find(delim);
	while (pos != std::string::npos) {
		v.push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);

		if (pos == std::string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

