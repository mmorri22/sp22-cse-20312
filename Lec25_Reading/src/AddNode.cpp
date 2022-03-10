#include "../include/AddNode.h"

// overload Constructor
AddNode::AddNode(Node* node1, Node* node2) : BinNode(node1,node2){ }

// destructor
 AddNode::~AddNode (){}

// Function
double AddNode::Calc() const{
	
  double val1 = this -> leftNode -> Calc();
  
  double val2 = this -> rightNode -> Calc();
  
  return val1 + val2;
  
}


