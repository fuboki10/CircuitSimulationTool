#pragma once
#include "element.h"
class Resistor :
	public CElement
{
	float value;	
public:
	Resistor(string i, node* n1, node* n2, float v);
	cx_float getValue();
	~Resistor(void);
};

