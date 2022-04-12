/**********************************************
* File: classIntro.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains examples of class constructor calls 
**********************************************/
#include "line.h"

int main(){

	point point1;
	
	std::cout << "point1 is " << point1 << std::endl;
	
	/* Update values */
	point1.setX( (COORDINATE)3.1 );
	point1.setY( (COORDINATE)6.2 );
	
	std::cout << "After update: point1 is " << point1 << std::endl;
	std::cout << std::endl;
	
	/* Second constructor for point */
	const point point2( (COORDINATE)-1.1, (COORDINATE)5.3 );
	
	std::cout << "point2 is " << point2 << std::endl  << std::endl;
	
	/* Default constructor for line */
	line line1;
	std::cout << "line1 is " << line1 << std::endl << std::endl;	
	
	/* Constructor qwith points for line */
	line line2(point1, point2);
	std::cout << "line2 is " << line2 << std::endl;
	std::cout << std::endl;	
	
	/* Constructor with COORDINATE for line */
	line line3(point2.getX(), point2.getY(), point1.getX(), point1.getY());
	std::cout << "line3 is " << line3 << std::endl << std::endl;	
	
	/* Print all slopes */
	std::cout << "line1 slope is " << line1.getSlope() << std::endl;
	std::cout << "line2 slope is " << line2.getSlope() << std::endl;
	std::cout << "line3 slope is " << line3.getSlope() << std::endl;
	
	return 0;
}
