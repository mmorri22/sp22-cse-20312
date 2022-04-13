#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
	public:
 
		// Virtual Destructor
		virtual ~Shape() {}
		
		// Dynamically Binded Area Function
		virtual int GetArea() const =0;
		
		// Dynamically Binded Draw Function
		virtual void Draw() const = 0;
};

#endif