#ifndef SUBNODE_H
#define SUBNODE_H

#include <iostream>
#include "BinNode.h"

class SubNode : public BinNode
{

	public:

	  // overload Constructor
	  SubNode(Node* node1, Node* node2);

	  // destructor
	   ~SubNode ();

	  // Function
	  double Calc() const;
};

#endif
