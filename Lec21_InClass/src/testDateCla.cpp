/*******************************************************
 * File Name: testDate.cpp 
 * Author Name: Matthew Morrison
 * E-mail: matt.morrison@nd.edu
 *
 * This file contains a sample solution for Challenge 1 
 * Part 1 where the Date is a class in "dateCla.h:
 *******************************************************/

#include <iostream>

#include "../include/dateCla.h"  // Contains Date Struct

/************************************
 * Function Name: printComp 
 * Pre-Conditions: std::ostream& out, DATE& , DATE&
 * Post-Conditions: void
 *
 * This function takes in two date, and prints a comparison to the 
 * user to the ostream&. If checkDate is the same day or after, it will 
 * indicate that to the user.
 *************************************/
void printComp(std::ostream& out, DATE& initialDate, DATE& checkDate){
    out << "The check date " << checkDate << " is" ;
    
	if(checkDate < initialDate)
        out << " before ";
    else
        out << " the same day or after ";
    
    out << "the initial date " << initialDate << std::endl;
}

/************************************
 * Function Name: main 
 * Pre-Conditions: int, char **
 * Post-Conditions: int
 *
 * This is the main driver function. 
 *************************************/
int main( )
{
    
    // Create the initial Date
    DATE initialDate(2021, 2, 22);
    
    // Create the earlier comparison
    DATE checkDate1(2021, 2, 17);
    
    // Create the same date comparison
    DATE checkDate2(2021, 2, 22);
    
    // Create the later date comparison
    DATE checkDate3(2021, 2, 26);
    
    // Make and print the comparisons
	printComp(std::cout, initialDate, checkDate1);
    printComp(std::cout, initialDate, checkDate2);
    printComp(std::cout, initialDate, checkDate3);

    return 0;
}
