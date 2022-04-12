#ifndef BINNODE_H
#define BINNODE_H

#include <iostream>
#include "Node.h"

class BinNode : public Node
{
	protected:
		Node* leftNode;
		Node* rightNode;

	public:
		//default constructor
		BinNode();

		// destructor
		virtual ~BinNode ();

		// overload Constructor
		BinNode(Node* Lnode, Node* Rnode);

		// copy constructor
		BinNode(const BinNode& copy);

		// assignmnet Operator
		BinNode& operator=(const BinNode& assign);
};

#endif