#include "node.h"
class CElement;
node::node(int a)
{
	n = a;
}
void node::AddElement(CElement* ce)
{
	c.push_back(ce);
}
int node::getn()
{
	return n;
}



node::~node(void)
{
}
