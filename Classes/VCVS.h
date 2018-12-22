#pragma once
#include "element.h"
#include <armadillo>
using namespace arma;
class VCVS :
	public CElement
{
	cx_float volt;
	const float B;
	node* INn1;
	node* INn2;
public:
	static int num;
	VCVS(string i, node* n1, node* n2, node* INn1, node* INn2, float B);
	void setVolt(float v);
	cx_float getValue();
	float getB() const;
	int getPostive();
	int getNegative();
	int getINPostive();
	int getINNegative();
	~VCVS(void);
};

