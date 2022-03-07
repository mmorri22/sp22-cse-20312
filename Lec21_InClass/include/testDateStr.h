/*******************************************************
 * File Name: testDate.cpp 
 * Author Name: Matthew Morrison
 * E-mail: matt.morrison@nd.edu
 *
 * This file contains a sample solution for Challenge 1 
 * Part 1 where the Date is a struct in "date.h:
 *******************************************************/

#include <iostream>

#include "date.h"  // Contains Date Struct

/************************************
 * Function Name: printComp 
 * Pre-Conditions: std::ostream& out, DATE& , DATE&
 * Post-Conditions: std::ostream&
 *
 * This function takes in two date, and prints a comparison to the 
 * user to the ostream&. If checkDate is the same day or after, it will 
 * indicate that to the user.
 *************************************/
std::ostream& printComp(std::ostream& out, DATE& initialDate, DATE& checkDate){
    out << "The check date " << checkDate << " is" ;
    
	if(checkDate < initialDate)
        out << " before ";
    else
        out << " the same day or after ";
    
    out << "the initial date " << initialDate << std::endl;
    
    return out;
}

/************************************
 * Function Name: main 
 * Pre-Conditions: int, char **
 * Post-Conditions: int
 *
 * This is the main driver function. 
 *************************************/
int main(int argc, char** argv)
{
    
    // Create the initial Date
    DATE initialDate = createDate(2019, 1, 23);
    
    // Create the earlier comparison
    DATE checkDate1 = createDate(2019, 1, 18);
    
    // Create the same date comparison
    DATE checkDate2 = createDate(2019, 1, 23);
    
    // Create the later date comparison
    DATE checkDate3 = createDate(2019, 1, 25);
    
    // Make and print the comparisons
    printComp(std::cout, initialDate, checkDate1);
    printComp(std::cout, initialDate, checkDate2);
    printComp(std::cout, initialDate, checkDate3);

    return 0;
}
