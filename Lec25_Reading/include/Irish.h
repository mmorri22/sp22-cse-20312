/**********************************************
* File: Irish.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* The function definitions for the Irish Base Class 
**********************************************/

#ifndef IRISH_H
#define IRISH_H

#include <string>
#include <iostream>

class Irish{
	
	protected:
	
		std::string lastName;
		std::string firstName;
		unsigned int ndID;
		std::string homeAddress;
	
	
	public:
		
		Irish(std::string lastIn, std::string firstIn, unsigned int ndIDIn);
		
		virtual ~Irish();
		
		void setHomeAddress(std::string homeAddrIn);
		
		virtual void printInformation();
		
		friend std::ostream& operator<<(std::ostream& output, const Irish& person);
	
};


#endif
