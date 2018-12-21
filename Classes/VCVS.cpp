#include "VCVS.h"

int VCVS::num = 0;
extern float pi;
VCVS::VCVS(string i, node* n1, node* n2, node* INn1, node* INn2, float B):CElement(i,n1,n2),B(B)
{
	this->INn1 = INn1;
	this->INn2 = INn2;
	num++;
}
void VCVS::setVolt(float v)
{
	volt = v;
}

cx_float VCVS::getValue()
{
	return volt;
}
float VCVS::getB() const
{
	return B;
}
int VCVS::getNegative()
{
	return getNode1()->getn();
}
int VCVS::getPostive()
{
	return getNode2()->getn();
}


VCVS::~VCVS(void)
{
}
