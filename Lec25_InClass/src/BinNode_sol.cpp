#include "../include/BinNode.h"

//default constructor
BinNode::BinNode() : leftNode(NULL), rightNode(NULL){}

// destructor
BinNode::~BinNode(){

  delete leftNode;
  delete rightNode;
}

// overload Constructor
BinNode::BinNode(Node* Lnode, Node* Rnode) : leftNode(Lnode), rightNode(Rnode){}