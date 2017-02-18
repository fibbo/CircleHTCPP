#include "stdafx.h"
#include "data.h"


Data::Data()
{
}


Data::~Data()
{
}

void Data::print(bool printCircles)
{
	std::cout << "Number of circles: " << m_iNumberOfCirles << std::endl;
	if (printCircles)
	{
		for (int i = 0; i < m_iNumberOfCirles; i++)
		{
			this->m_circles[i].print();
		}
	}
	
}
