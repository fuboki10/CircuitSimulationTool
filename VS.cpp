#include "VS.h"

int VS::num = 0;
extern float pi;
VS::VS(string i, node* n1, node* n2, float v, float p) : CElement(i, n1, n2)
{
	phase = p;
	volt = polar(v, p * pi/180);
	num++;
}

void VS::setVolt(float v)
{
	volt = v;
}

cx_float VS::getValue()
{
	return volt;
}
int VS::getNegative()
{
	return getNode1()->getn();
}
int VS::getPostive()
{
	return getNode2()->getn();
}


VS::~VS(void)
{
}
