#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	public:
		virtual ~Node () {}
		virtual double Calc () const = 0;
};


#endif