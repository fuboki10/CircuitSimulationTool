#pragma once
#include "element.h"
#include <armadillo>

using namespace arma;
class Inductor :
	public CElement
{
	float ind;
	cx_float cx_ind;
	cx_float amp;
public:
	Inductor(string i, node* n1, node* n2, float v);
	cx_float getValue();
	cx_float getAmp()
	{
		return amp;
	}

	~Inductor(void);
};

