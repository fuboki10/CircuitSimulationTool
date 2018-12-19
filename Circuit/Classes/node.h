#pragma once
#include <vector>
#include "Element.h"
class CElement;
class node
{
	int n;
public:
	std::vector<CElement*> c;
	node(int a);
	void AddElement(CElement* ce);
	int getn();
	~node(void);
};

