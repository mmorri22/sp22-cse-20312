#ifndef MULTNODE_H
#define MULTNODE_H

#include <iostream>
#include "BinNode.h"

class MultNode : public BinNode
{

	public:

	  // overload Constructor
	  MultNode(Node* node1, Node* node2);

	  // destructor
	   ~MultNode ();

	  // Function
	  double Calc() const;
  
};

#endif
