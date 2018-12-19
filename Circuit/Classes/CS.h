#pragma once
#include "element.h"
#include <armadillo>
using namespace arma;
class CS :
	public CElement
{
	cx_float current;
	float phase;
public:
	static int num;
	CS(string i, node* n1, node* n2, float v, float p = 0);
	void setCurrent(float c);
	cx_float getValue();
	int into();
	int from();
	~CS(void);
};

