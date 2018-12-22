#include "CCCS.h"
extern float pi;
int CCCS::num = 0;
CCCS::CCCS(string i, node* n1, node* n2, node* INn1, node* INn2, float B, float p) : CElement(i,n1,n2),B(B)
{
	phase = p;
	this->INn1 = INn1;
	this->INn2 = INn2;
	num++;
}
void CCCS::setCurrent(float c)
{
	current = c;
}

cx_float CCCS::getValue()
{
	return current;
}
float CCCS::getB() const
{
	return B;
}
int CCCS::from()
{
	return getNode1()->getn();
}

int CCCS::into()
{
	return getNode2()->getn();
}

int::CCCS::INfrom()
{
	return INn1->getn();
}

int::CCCS::INinto()
{
	return INn2->getn();
}
CCCS::~CCCS()
{
}
