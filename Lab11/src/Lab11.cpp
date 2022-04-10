#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Triangle.h"


int main()
{

  Shape *shapePtr;	       	/* Base class pointer */
  Rectangle aRectangle(5,4);  	/* creating a rectangle object */
  Triangle aTriangle(4,4);    	/* creating a triangle object */

  /* Write code to perform dynamic binding here */
  
  return 0;
}
