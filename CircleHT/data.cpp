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
    for (int j = 0; j < m_points.size() - 2; j++)
    {
        for (int k = j + 1; k < m_points.size() - 1; k++)
        {
            for (int l = k + 1; l < m_points.size(); l++)
            {
                Triplet* p = new Triplet(m_points[j], m_points[k], m_points[l]);
                m_triplets.push_back(p);
            }
        }
    }
}

void Data::create_rings()
{
    for (int i = 0; i < m_triplets.size(); i++)
    {
        BSE::Point *A, *B, *C;
        A = m_triplets[i]->points[0];
        B = m_triplets[i]->points[1];
        C = m_triplets[i]->points[2];
    }
}
