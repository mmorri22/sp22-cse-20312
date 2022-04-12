#include "../include/DivNode.h"

// overload Constructor
DivNode::DivNode(Node* node1, Node* node2) : BinNode(node1,node2){ }

// destructor
 DivNode::~DivNode (){}

// Function
double DivNode::Calc() const{
	
  double val1 = this -> leftNode -> Calc();
  
  double val2 = this -> rightNode -> Calc();
  
  return val1 / val2;
  
}

