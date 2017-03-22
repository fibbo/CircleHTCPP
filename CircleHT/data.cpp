#include "stdafx.h"
#include "data.h"
#include <algorithm>

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
    for (int j = 0; j < m_points->size() - 2; j++)
    {
        for (int k = j + 1; k < m_points->size() - 1; k++)
        {
            for (int l = k + 1; l < m_points->size(); l++)
            {
                BSE::Triplet<float>* p = new BSE::Triplet<float>(m_points->at(j), m_points->at(k), m_points->at(l));
                m_triplets->push_back(p);
            }
        }
    }
}

void Data::create_rings()
{
    for (int i = 0; i < m_triplets->size(); i++)
    {
        BSE::Point<float> *A, *B, *C;
        A = m_triplets->at(i)->points[0];
        B = m_triplets->at(i)->points[1];
        C = m_triplets->at(i)->points[2];

        float a, b, c;
        a = (*C - *B).norm();
        b = (*C - *A).norm();
        c = (*B - *A).norm();

        if ( a > 0.30 || b > 0.30 || c > 0.30)
            continue;
        float s = (a + b + c) / 2;
        float R = a * b * c / 4 / sqrt(s * (s - a) * (s - b) * (s - c));
        if (R < 0.30 / 2)
        {
            float a2, b2, c2;

            a2 = a*a;
            b2 = b*b;
            c2 = c*c;

            float l1, l2, l3;
            l1 = a2 * (b2 + c2 - a2);
            l2 = b2 * (a2 + c2 - b2);
            l3 = c2 * (a2 + b2 - c2);

            BSE::Point<float> c(A->x*l1 + B->x*l2 + C->x*l3, A->y*l1 + B->y*l2 + C->y*l3);
            c /= (l1 + l2 + l3);
            BSE::Ring<float>* r = new BSE::Ring<float>(c, R);
            m_rings.push_back(r);
        }
    }
    // I don't need them anymore
    delete m_triplets;
    m_triplets = nullptr;
}

void Data::sort_rings()
{
    std::sort(m_rings.begin(), m_rings.end(),
        [](const BSE::Ring<float>* a, const BSE::Ring<float>* b)
    {
        return a->m_radius > b->m_radius;
    });
}
