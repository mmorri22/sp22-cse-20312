#include "../include/MultNode.h"

// overload Constructor
MultNode::MultNode(Node* node1, Node* node2) : BinNode(node1,node2){ }

// destructor
 MultNode::~MultNode (){}

// Function
double MultNode::Calc() const{
	
  double val1 = this -> leftNode -> Calc();
  
  double val2 = this -> rightNode -> Calc();
  
  return val1*val2;
  
}

