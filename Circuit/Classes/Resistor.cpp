#include "Resistor.h"


Resistor::Resistor(string i, node* n1, node* n2, float v) : CElement(i, n1, n2)
{
	value = v;
}
cx_float Resistor::getValue()
{
	return value;
}



Resistor::~Resistor(void)
{
}
