#include "CCVS.h"

int CCVS::num = 0;
extern float pi;
CCVS::CCVS(string i, node* n1, node* n2, node* INn1, node* INn2, float B):CElement(i,n1,n2),B(B)
{
	this->INn1 = INn1;
	this->INn2 = INn2;
	num++;
}
void CCVS::setVolt(float v)
{
	volt = v;
}

cx_float CCVS::getValue()
{
	return volt;
}
float CCVS::getB() const
{
	return B;
}
int CCVS::getNegative()
{
	return getNode1()->getn();
}
int CCVS::getPostive()
{
	return getNode2()->getn();
}
int CCVS::INfrom()
{
	return INn1->getn();
}
int CCVS::INinto()
{
	return INn2->getn();
}


CCVS::~CCVS(void)
{
}
