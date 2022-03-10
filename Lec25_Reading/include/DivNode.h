#ifndef DIVNODE_H
#define DIVNODE_H

#include <iostream>
#include "BinNode.h"

class DivNode : public BinNode
{

	public:

	  // overload Constructor
	  DivNode(Node* node1, Node* node2);

	  // destructor
	   ~DivNode ();

	  // Function
	  double Calc() const;
};

#endif
