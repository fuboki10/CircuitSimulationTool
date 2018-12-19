#pragma once
#include "element.h"
#include <armadillo>

using namespace arma;
class Capacitor :
	public CElement
{
	float cap;
	cx_float cx_cap;
	cx_float amp;
public:
	Capacitor(string i, node* n1, node* n2, float v);
	cx_float getValue();
	cx_float getAmp()
	{
		return amp;
	}
	~Capacitor(void);
};

