#pragma once
#include "element.h"
#include <armadillo>
using namespace arma;
class VCCS :
	public CElement
{
	float phase;
	cx_float current;
	const float B;
	node* INn1;
	node* INn2;
public:
	static int num;
	VCCS(string i, node* n1, node* n2, node* INn1, node* INn2, float B, float p = 0);
	void setCurrent(float c);
	cx_float getValue();
	float getB() const;
	int into();
	int from();
	int INinto();
	int INfrom();
	~VCCS(void);
};

