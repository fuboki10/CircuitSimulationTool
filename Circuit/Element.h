#pragma once
#include <iostream>
#include <string>
#include <armadillo>
#include "node.h"
using namespace std;
using namespace arma;
extern float omega;
class node;
class CElement
{
	string id;
	node* n1;
	node* n2;
public:
	CElement(string i, node* n1, node* n2);
	void setID(string id);
	void setNodes(node* n1, node* n2);
	node* getNode1();
	node* getNode2();
	bool isConnect(int n);
	int getN(int n);
	string getid();
	virtual cx_float getValue() 
	{
		return 0;
	}

	~CElement(void);
};

