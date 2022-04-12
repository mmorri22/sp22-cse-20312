#include "../include/NumNode.h"

// overload Constructor
NumNode::NumNode(double numIN) : num(numIN){ }

// destructor
NumNode::~NumNode (){}

// overloaded method
double NumNode::Calc() const{
	
  return this -> num;
  
}
