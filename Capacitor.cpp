#include "Capacitor.h"

Capacitor::Capacitor(string i, node* n1, node* n2, float v) : CElement(i, n1, n2)
{
	cap = v;
	cx_cap = cx_float(0,-1/(v * omega));
	amp = cx_float(0, v * omega);
}
cx_float Capacitor::getValue()
{
	return cx_cap;
}


Capacitor::~Capacitor(void)
{
}
