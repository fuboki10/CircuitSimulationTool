#pragma once
#include "element.h"
#include <armadillo>
using namespace arma;
class CCVS :
	public CElement
{
	cx_float volt;
	const float B;
	node* INn1;
	node* INn2;
public:
	static int num;
	CCVS(string i, node* n1, node* n2, node* INn1, node* INn2, float B);
	void setVolt(float v);
	cx_float getValue();
	float getB() const;
	int getPostive();
	int getNegative();
	int INfrom();
	int INinto();
	~CCVS(void);
};

