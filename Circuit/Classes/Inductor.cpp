#include "Inductor.h"


Inductor::Inductor(string i, node* n1, node* n2, float v) : CElement(i, n1, n2)
{
	ind = v;
	cx_ind = cx_float(0,v * omega);
	amp = cx_float(0, -1/(v * omega));
}
cx_float Inductor::getValue()
{
	return cx_ind;
}


Inductor::~Inductor(void)
{
}
