#pragma once
#include "element.h"
#include <armadillo>
using namespace arma;
class CCCS :
	public CElement
{
	cx_float current;
	const float B;
	node* INn1;
	node* INn2;
public:
	static int num;
	CCCS(string i, node* n1, node* n2, node* INn1, node* INn2, float B);
	void setCurrent(float c);
	cx_float getValue();
	float getB() const;
	int into();
	int from();
	int INinto();
	int INfrom();
	~CCCS(void);
};

