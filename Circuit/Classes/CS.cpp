#include "CS.h"
extern float pi;
int CS::num = 0;
CS::CS(string i, node* n1, node* n2, float v, float p) : CElement(i, n1, n2)
{
	phase = p;
	current = polar(v, p * pi/180);
	num++;
}
void CS::setCurrent(float c)
{
	current = c;
}

cx_float CS::getValue()
{
	return current;
}
int CS::from()
{
	return getNode1()->getn();
}

int CS::into()
{
	return getNode2()->getn();
}

CS::~CS(void)
{
}
