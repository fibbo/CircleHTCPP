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

void Data::create_triplets()
{
    for (int j = 0; j < m_points.size()-2; j++)
    {
        for (int k = j+1; k < m_points.size()-1; k++)
        {
            for (int l = k+1; l < m_points.size(); l++)
            {
                Triplet p;
                p.points[0] = m_points[j];
                p.points[1] = m_points[k];
                p.points[2] = m_points[l];
                m_triplets.push_back(p);
            }
        }
    }
}

