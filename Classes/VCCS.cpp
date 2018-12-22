#include "VCCS.h"
extern float pi;
int VCCS::num = 0;
VCCS::VCCS(string i, node* n1, node* n2, node* INn1, node* INn2,float B, float p) : CElement(i,n1,n2),B(B)
{
	phase = p;
	this->INn1 = INn1;
	this->INn2 = INn2;
	num++;
}
void VCCS::setCurrent(float c)
{
	current = c;
}

cx_float VCCS::getValue()
{
	return current;
}
float VCCS::getB() const
{
	return B;
}
int VCCS::from()
{
	return getNode1()->getn();
}

int VCCS::into()
{
	return getNode2()->getn();
}

int::VCCS::INfrom()
{
	return INn1->getn();
}

int::VCCS::INinto()
{
	return INn2->getn();
}

VCCS::~VCCS(void)
{
}
