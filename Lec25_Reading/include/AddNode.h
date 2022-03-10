#ifndef ADDNODE_H
#define ADDNODE_H

#include <iostream>
#include "BinNode.h"

class AddNode : public BinNode
{

	public:

	  // overload Constructor
	  AddNode(Node* node1, Node* node2);

	  // destructor
	   ~AddNode ();

	  // Function
	  double Calc() const;
};

#endif

