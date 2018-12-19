#include "Element.h"
class node;
CElement::CElement(string i, node* n1, node* n2)
{
	id = i;
	this->n1 = n1;
	this->n2 = n2;
	this->n1->AddElement(this);
	this->n2->AddElement(this);
}
void CElement::setID(string id)
{
	this->id = id;
}
void CElement::setNodes(node* n1, node* n2)
{
	this->n1 = n1;
	this->n2 = n2;
	this->n1->AddElement(this);
	this->n2->AddElement(this);
}
node* CElement::getNode1()
{
	return n1;
}
node* CElement::getNode2()
{
	return n2;
}
string CElement::getid()
{
	return id;
}


bool CElement::isConnect(int n)
{
	return (n == getNode1()->getn() || n == getNode2()->getn()); 	
}

int CElement::getN(int n)
{
	return (n == n1->getn()) ? n2->getn() : n1->getn();
}

CElement::~CElement(void)
{
}
