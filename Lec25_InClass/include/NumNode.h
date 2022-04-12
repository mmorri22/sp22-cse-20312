#ifndef NUMNODE_H
#define NUMNODE_H

#include <iostream>
#include "Node.h"

class NumNode : public Node
{
	protected:
		double num;

	public:

	  // Constructor
	  NumNode(double numIN);

	  // destructor
	  virtual ~NumNode ();

	  // overloaded method
	  double Calc() const;
};


#endif
