#include <fstream>
#include "Classes//node.h"
#include "Classes//CS.h"
#include "Classes//VS.h"
#include "Classes//Resistor.h"
#include "Classes//Capacitor.h"
#include "Classes//Inductor.h"
#include "Classes\VCCS.h"
#include "Classes\CCCS.h"
float pi = 3.14159265358979323846;
float omega = 50;

/*
//////////////////////////////////////////////////////////////////////
	read more about Modified nodal analysis
	https://www.swarthmore.edu/NatSci/echeeve1/Ref/mna/MNA3.html
/////////////////////////////////////////////////////////////////////
*/

int main()
{
	
	vector <CElement*> circuit;
	vector <node*> nod;
	vector <VS*> vs;
	vector <CS*> cs;
	vector <VCCS*> vccs;
	vector <CCCS*> cccs;
	vector <Resistor*> r;
	vector <Capacitor*> c;
	vector <Inductor*> l;
	fstream fin;
	string id;
	int n1;
	int n2;
	node* n1ptr = NULL;
	node* n2ptr = NULL;
	float value;
	//reading the input netlist
	fin.open("input.txt");
	//if there is a value in the text file at the begining of the file, assign this value for omega
	if(!(fin>>omega))
	{
		fin.close();
		fin.open("input.txt");
		char c = fin.peek();
		while(c != 'V' && c != 'v' && c != 'i' && c != 'I' && c != 'c' && c != 'C' && c != 'R' && c != 'r' && c != 'l'&& c != 'L')
		{
			fin.get(c);
			c = fin.peek();
		}

	}
	//reading the rest of the file
	//Note: in case of current and voltage sources
	//the negative is the first node typed
	//the postive is the second node typed
	while(!fin.eof())
	{
		//creating nodes
		n1ptr = NULL;
		n2ptr = NULL;
		fin>>id;
		fin>>n1;
		//checking if the nodes already exists
		for(int i = 0; i < nod.size(); i++)
		{
			if(n1 == nod[i]->getn())
			{
				n1ptr = nod[i];
				break;
			}

		}
		fin>>n2;
		for(int i = 0; i < nod.size(); i++)
		{
			if(n2 == nod[i]->getn())
			{
				n2ptr = nod[i];
				break;
			}
		}
		//if the nodes are not there
		//create them
		if(!n1ptr)
		{
			nod.push_back(new node(n1));
			n1ptr = nod[nod.size() - 1];
		}
		if(!n2ptr)
		{
			nod.push_back(new node(n2));
			n2ptr = nod[nod.size() - 1];
		}
		//creating the element
		switch (id[0])
		{
		case 'I':
		case 'i':
		{
			fin>>value;
			float phase;
			fin>>phase;
			CS* tmpc = new CS(id, n1ptr, n2ptr, value, phase);
			circuit.push_back(tmpc);
			cs.push_back(tmpc);
			break;
		}
		case 'V':
		case 'v':
			{
				fin>>value;
				float phase;
				fin>>phase;
				VS* tmpv = new VS(id, n1ptr, n2ptr, value, phase);
				circuit.push_back(tmpv);
				vs.push_back(tmpv);
				break;
			}
		case 'r':
		case 'R':
			{
				fin>>value;
				Resistor* tmp = new Resistor(id, n1ptr, n2ptr, value);
				circuit.push_back(tmp);
				r.push_back(tmp);
				break;
			}
		case 'C':
		case 'c':
			{
				fin>>value;
				Capacitor* tmp = new Capacitor(id, n1ptr, n2ptr, value);
				circuit.push_back(tmp);
				c.push_back(tmp);
				break;
			}
		case 'L':
		case 'l':
			{
				fin>>value;
				Inductor* tmp = new Inductor(id, n1ptr, n2ptr, value);
				circuit.push_back(tmp);
				l.push_back(tmp);
				break;
			}
		case 'G':
		case 'g':
			{
				node* INn1ptr = NULL;
				node* INn2ptr = NULL;
				fin>>value;
				float phase;
				fin>>phase;
				fin>>n1;
				//checking if the nodes already exists
				for(int i = 0; i < nod.size(); i++)
				{
					if(n1 == nod[i]->getn())
					{
						INn1ptr = nod[i];
						break;
					}
				}
				fin>>n2;
				for(int i = 0; i < nod.size(); i++)
				{
					if(n2 == nod[i]->getn())
					{
						INn2ptr = nod[i];
						break;
					}
				}
				//if the nodes are not there
				//create them
				if(!INn1ptr)
				{
					nod.push_back(new node(n1));
					INn1ptr = nod[nod.size() - 1];
				}
				if(!INn2ptr)
				{
					nod.push_back(new node(n2));
					INn2ptr = nod[nod.size() - 1];
				}
				VCCS* tmp = new VCCS(id, n1ptr, n2ptr, INn1ptr, INn2ptr, value, phase);
				circuit.push_back(tmp);
				vccs.push_back(tmp);
				break;
			}
		case 'F':
		case 'f':
			{
				node* INn1ptr = NULL;
				node* INn2ptr = NULL;
				fin>>value;
				float phase;
				fin>>phase;
				fin>>n1;
				//checking if the nodes already exists
				for(int i = 0; i < nod.size(); i++)
				{
					if(n1 == nod[i]->getn())
					{
						INn1ptr = nod[i];
						break;
					}
				}
				fin>>n2;
				for(int i = 0; i < nod.size(); i++)
				{
					if(n2 == nod[i]->getn())
					{
						INn2ptr = nod[i];
						break;
					}
				}
				//if the nodes are not there
				//create them
				if(!INn1ptr)
				{
					nod.push_back(new node(n1));
					INn1ptr = nod[nod.size() - 1];
				}
				if(!INn2ptr)
				{
					nod.push_back(new node(n2));
					INn2ptr = nod[nod.size() - 1];
				}
				CCCS* tmp = new CCCS(id, n1ptr, n2ptr, INn1ptr, INn2ptr, value, phase);
				circuit.push_back(tmp);
				cccs.push_back(tmp);
				break;

			}

			 //circuit.push_back(CS(
		}


	}
	//according to the modified nodal analysis algorithm we create two matrices
	//A x = Z
	//A matrix consists of 4 matrices
	//assuming that the circuit doesn't contain dependent sources
	//we will call The upper left matrix G, The upper right matrix B, The lower left matrix C and the lower right matrix Z

	//Creating matrix G
	//G is node_count x node_count square matrix
	//matrix G contains the one over impedances(admittance) summation for the passive elements connected to this node(i'th node) (Resistor, Capacitor, Inductor)
	//at i x i

	//at i x j ( i != j) contains the negative summation of the admittances connected to these nodes
	cx_fmat G(nod.size() - 1, nod.size() - 1, fill::zeros);
	//note: we don't count the node 0
	//note: armadillo matrices are zero indexed
	for(int i = 0; i < nod.size(); i++)
	{
		//for every node in the circuit
		//if the j'th element connected to this i'th node is (Resistor, Capacitor, Inductor) subtract its value from the element (the another node ,i - 1)
		for(int j = 0; j < nod[i]->c.size(); j++)
		{
			if(nod[i]->c[j]->getN(nod[i]->getn()) != 0 && (dynamic_cast<Resistor*>(nod[i]->c[j]) || dynamic_cast<Capacitor*>(nod[i]->c[j]) || dynamic_cast<Inductor*>(nod[i]->c[j])) && nod[i]->c[j]->getN(i) != i && nod[i]->getn() != 0)
			{
				G(nod[i]->c[j]->getN(nod[i]->getn()) - 1, nod[i]->getn() - 1) += cx_float(-1)/nod[i]->c[j]->getValue();
			}


		}
		//for every (passive) element in in the circuit add its value to the element (i - 1, i - 1)
		for(int j = 0; j < nod[i]->c.size(); j++)
		{
			if((dynamic_cast<Resistor*>(nod[i]->c[j]) || dynamic_cast<Capacitor*>(nod[i]->c[j]) || dynamic_cast<Inductor*>(nod[i]->c[j])) && nod[i]->getn() != 0)
			{
				G(nod[i]->getn() - 1, nod[i]->getn() - 1) += cx_float(1)/nod[i]->c[j]->getValue();
			}


		}

	}
	//G.print("G: ");
	//Creating both B and C matrices
	//Actually B = C(transpose) in case of independent sources
	//Read the modified nodal analysis algorithm to know more about these matrices
	cx_fmat B(nod.size() - 1, vs.size() + vccs.size() + cccs.size(), fill::zeros);
	cx_fmat C(vs.size() + vccs.size() + cccs.size(), nod.size() - 1, fill::zeros);
	int end = vs.size();
	for(int i = 0; i < end; i++)
	{
		if(vs[i]->getPostive() != 0)
		{
			B(vs[i]->getPostive() - 1, i) = 1;
			C(i ,vs[i]->getPostive() - 1) = 1;
		}
		if(vs[i]->getNegative() != 0)
		{
			B(vs[i]->getNegative() - 1, i) = -1;
			C(i ,vs[i]->getNegative() - 1) = -1;
		}

	}
	int start = end;
	end += vccs.size();
	for (int i = start; i < end; i++)
	{
		if(vccs[i-start]->from() != 0)
		{
			B(vccs[i-start]->from() - 1, i) = 1;
		}
		if(vccs[i-start]->into() != 0)
		{
			B(vccs[i-start]->into() - 1, i) = -1;
		}
		if(vccs[i-start]->INfrom() != 0)
		{
			C(i ,vccs[i-start]->INfrom() - 1) = 1;
		}
		if(vccs[i-start]->INinto() != 0)
		{
			C(i ,vccs[i-start]->INinto() - 1) = -1;
		}
	}
	start = end;
	end += cccs.size();
	for (int i = start; i < end; i++)
	{
		if(cccs[i-start]->from() != 0)
		{
			B(cccs[i-start]->from() - 1, i) = 1;
		}
		if(cccs[i-start]->into() != 0)
		{
			B(cccs[i-start]->into() - 1, i) = -1;
		}
		if(cccs[i-start]->INfrom() != 0)
		{
			B(cccs[i-start]->INfrom() - 1, i) = (cx_float)(1)/cccs[i-start]->getB();
			C(i ,cccs[i-start]->INfrom() - 1) = 1;
		}
		if(cccs[i-start]->INinto() != 0)
		{
			B(cccs[i-start]->INinto() - 1, i) = (cx_float)(-1)/cccs[i-start]->getB();
			C(i ,cccs[i-start]->INinto() - 1) = -1;
		}
	}
	//B.print("B: ");
	//C.print("C: ");
	cx_fmat D(cccs.size() + vccs.size() + vs.size(),cccs.size() + vccs.size() + vs.size(), fill::zeros);
	for (int i = vs.size(); i < vs.size() + vccs.size(); i++)
	{
		D(i,i) = (cx_float)(-1)/vccs[i - vs.size()]->getB();
	}
	//Creating matrix z
	//Matrix z consists of 2 matrices
	//Read more about modified nodal analysis
	cx_fmat z(nod.size() - 1 + vs.size() + vccs.size() + cccs.size(), 1, fill::zeros);
	for(int i = 0; i < cs.size(); i++)
	{
		if(cs[i]->from() != 0)
		{
			z(cs[i]->from() - 1, 0) -= cs[i]->getValue();
		}
		if(cs[i]->into() != 0)
		{
			z(cs[i]->into() - 1, 0) += cs[i]->getValue();
		}
	}
	for(int i = nod.size() - 1; i < nod.size() - 1 + vs.size(); i++)
	{
		z(i, 0) = vs[i - nod.size() + 1]->getValue();
	}
	//z.print("Z:");
	//Combining the four matrices to create the matrix A
	//Note : A x = Z
	//x is the solution
	cx_fmat A(cccs.size() + vccs.size() + vs.size() + nod.size() - 1, cccs.size() + vccs.size() + vs.size() + nod.size() - 1, fill::zeros);
	for(int i = 0; i < nod.size() - 1; i++)
	{
		for(int j = 0; j < nod.size() - 1; j++)
		{
			A(i, j) = G(i, j);
		}

	}
	for(int i = 0; i < nod.size() - 1; i++)
	{
		for(int j = nod.size() - 1; j < cccs.size() + vccs.size() + vs.size() + nod.size() - 1; j++)
		{
			A(i, j) = B(i, j - nod.size() + 1);
		}

	}
	for(int i = nod.size() - 1; i < cccs.size() + vccs.size() + vs.size() + nod.size() - 1; i++)
	{
		for(int j = 0; j < nod.size() - 1; j++)
		{
			A(i, j) = C(i - nod.size() + 1, j);
		}

	}
	for(int i = nod.size() - 1; i < cccs.size() + vccs.size() + vs.size() + nod.size() - 1; i++)
	{
		for(int j = nod.size() - 1; j < cccs.size() + vccs.size() + vs.size() + nod.size() - 1; j++)
		{
			A(i, j) = D(i - nod.size() + 1, j - nod.size() + 1);
		}

	}
	//A.print("A: ");
	//create the solution matrix
	cx_fmat x = cx_fmat(1, cccs.size() + vccs.size() + vs.size() + nod.size() - 1);
	x = solve(A, z);
	//x.print("X:");
	//printing the solution in a nice way
	for(int i = 0; i < nod.size() - 1; i++)
	{
		float mag = sqrt(norm(x(i)));
		float phase = arg(x(i)) * 180/pi;
		(x(i).imag() == 0 && x(i).real() == 0) ? cout<<"voltage of node "<<i + 1<<" = "<<mag<<endl : cout<<"voltage of node "<<i + 1<<" = "<<mag<<" "<<phase<<endl;
	}
	/*for(int i = 0; i < circuit.size(); i++)
	{
		int n1 = circuit[i]->getNode1()->getn();
		int n2 = circuit[i]->getNode2()->getn();
		cx_float volt;
		if(n1 == 0 || n2 == 0)
		{
			volt = (n1 == 0) ? -(x(n2 - 1)) : (x(n1 - 1));
		}
		else
		{
			volt = (x(n1 - 1) - x(n2 - 1));
		}
		float mag = sqrt(norm(volt));
		float phase = arg(volt) * 180/pi;
		(volt.imag() == 0 && volt.real() == 0) ? cout<<"voltage of "<<circuit[i]->getid()<<" ("<<n1<<" "<<n2<<")"<<" = "<<mag<<endl : cout<<"voltage of "<<circuit[i]->getid()<<" ("<<n1<<" "<<n2<<") "<<" = "<<mag<<" "<<phase<<endl;
	}*/
	start = 0;
	end = vs.size();
	for(int i = start; i < end; i++)
	{
		float mag = sqrt(norm(x(nod.size() - 1 + i)));
		float phase = arg(x(nod.size() - 1 + i)) * 180/pi;
		phase = (phase == -0) ? 0 : phase;
		cout<<"current in "<<vs[i]->getid()<<" ("<<vs[i]->getPostive()<<" "<<vs[i]->getNegative()<<")"<<" source = "<<mag<<" "<<phase<<endl;
	}
	start = end;
	end += vccs.size();
	for (int i = start; i < end; i++)
	{
		float mag = sqrt(norm(x(nod.size() - 1 + i)));
		float phase = arg(x(nod.size() - 1 + i)) * 180/pi;
		phase = (phase == -0) ? 0 : phase;
		cout<<"current in "<<vccs[i - start]->getid()<<" ("<<vccs[i - start]->from()<<" "<<vccs[i - start]->into()<<")"<<" source = "<<mag<<" "<<phase<<endl;
	}
	start = end;
	end += cccs.size();
	for (int i = start; i < end; i++)
	{
		float mag = sqrt(norm(x(nod.size() - 1 + i)));
		float phase = arg(x(nod.size() - 1 + i)) * 180/pi;
		phase = (phase == -0) ? 0 : phase;
		cout<<"current in "<<cccs[i - start]->getid()<<" ("<<cccs[i - start]->from()<<" "<<cccs[i - start]->into()<<")"<<" source = "<<mag<<" "<<phase<<endl;
	}
	for(int i = 0; i < r.size(); i++)
	{
		cx_float c;
		if(r[i]->getNode1()->getn() == 0 || r[i]->getNode2()->getn() == 0)
		{
			c = (r[i]->getNode1()->getn() == 0) ? (x(r[i]->getNode2()->getn() - 1)) / r[i]->getValue() : (x(r[i]->getNode1()->getn() - 1)) / r[i]->getValue();
		}
		else
		{
			c = (x(r[i]->getNode1()->getn() - 1) - x(r[i]->getNode2()->getn() - 1)) / r[i]->getValue();
		}
		float phase = arg(c) * 180/pi;
		phase = (phase == -0) ? 0 : phase;
		float mag = sqrt(norm(c));
		cout<<"current in "<<r[i]->getid()<<" ("<<r[i]->getNode1()->getn()<<" "<<r[i]->getNode2()->getn()<<")"<<" = "<<mag<<" "<<phase<<endl;
	}
	
	for(int i = 0; i < c.size(); i++)
	{
		cx_float tmp;
		if(c[i]->getNode1()->getn() == 0 || c[i]->getNode2()->getn() == 0)
		{
			tmp = (c[i]->getNode1()->getn() == 0) ? (x(c[i]->getNode2()->getn() - 1)) / c[i]->getValue() : (x(c[i]->getNode1()->getn() - 1)) / c[i]->getValue();
		}
		else
		{
			tmp = (x(c[i]->getNode1()->getn() - 1) - x(c[i]->getNode2()->getn() - 1)) / c[i]->getValue();
		}
		float mag = sqrt(norm(tmp));
		float phase = arg(tmp) * 180/pi;
		phase = (phase == -0) ? 0 : phase;
		cout<<"current in "<<c[i]->getid()<<" ("<<c[i]->getNode1()->getn()<<" "<<c[i]->getNode2()->getn()<<")"<<" = "<<mag<<" "<<phase<<endl;
	}
	
	for(int i = 0; i < l.size(); i++)
	{
		cx_float tmp;
		if(l[i]->getNode1()->getn() == 0 || l[i]->getNode2()->getn() == 0)
		{
			tmp = (l[i]->getNode1()->getn() == 0) ? (x(l[i]->getNode2()->getn() - 1)) / l[i]->getValue() : (x(l[i]->getNode1()->getn() - 1)) / l[i]->getValue();
		}
		else
		{
			tmp = (x(l[i]->getNode1()->getn() - 1) - x(l[i]->getNode2()->getn() - 1)) / l[i]->getValue();
		}
		float phase = arg(tmp) * 180/pi;
		phase = (phase == -0) ? 0 : phase;
		float mag = sqrt(norm(tmp));
		cout<<"current in "<<l[i]->getid()<<" ("<<l[i]->getNode1()->getn()<<" "<<l[i]->getNode2()->getn()<<")"<<" = "<<mag<<" "<<phase<<endl;
	}

	//freeing the dynamically allocated memory
	for(int i = 0; i < circuit.size(); i++)
	{
		delete circuit[i]; //nice delete 
	}
	for(int i = 0; i < nod.size(); i++)
	{
		delete nod[i];
	}
}	