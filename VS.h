#pragma once
#include "element.h"
#include <armadillo>
using namespace arma;
class VS :
	public CElement
{
	cx_float volt;
	float phase;
public:
	static int num;
	VS(string i, node* n1, node* n2, float v, float p = 0);
	void setVolt(float v);
	cx_float getValue();
	int getPostive();
	int getNegative();
	~VS(void);
};

