#include "../include/SubNode.h"

// overload Constructor
SubNode::SubNode(Node* node1, Node* node2) : BinNode(node1,node2){ }

// destructor
 SubNode::~SubNode (){}

// Function
double SubNode::Calc() const{
	
  double val1 = this -> leftNode -> Calc();
  
  double val2 = this -> rightNode -> Calc();
  
  return val1-val2;
  
}

