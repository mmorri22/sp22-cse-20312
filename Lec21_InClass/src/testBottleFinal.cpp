/****************************************
 * File name: testBottleFinal.cpp 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the 
 * bottle class for the Project 1 Pharmacy Simulator
 * Part 1 - test the overlap operators for the 
 * Bottle Class 
 * *************************************/

#include <iostream>
#include <fstream>

#include "../include/bottleFinal.h"    // Includes "date.h"

/************************************
 * Function Name: main 
 * Preconditions: int, char**
 * Postconditions: int  
 * Main driver function creates three Bottles and 
 * compares them using the >, <, ==, and != operators 
 * *********************************/
int main(int argc, char** argv)
{
    
    // Create the initial Bottle
    DATE date1 = createDate(2019, 1, 23); // EXP: 2019 JAN 23 
    int lot_num = 45; // 45 pills 
    std::string drugName = "Azithromycin";
    
    // Create the larger Bottle
    DATE date2 = createDate(2019, 1, 23); // EXP: 2019 JAN 23 
    int lot_num2 = 45; // 45 pills 
    std::string drugName2 = "Lisinopril";
    
    // Create the larger Bottle
    DATE date3 = createDate(2019, 1, 23); // EXP: 2019 JAN 23 
    int lot_num3 = 50; // 45 pills 
    std::string drugName3 = "Azithromycin";
    
    // Create constructors
    Bottle bottle1(drugName, lot_num, date1);
    Bottle bottle2(drugName2, lot_num2, date2);
    Bottle bottle3(drugName3, lot_num3, date3);
    
	// Print the contents of both bottles to the screen.
    std::cout << "Bottle1: " << bottle1 << std::endl;
    std::cout << "Bottle2: " << bottle2 << std::endl;
    std::cout << "Bottle3: " << bottle3 << std::endl;
    
    // Prove the < operator
    if(bottle1 < bottle2){
        std::cout << "Bottle1 < Bottle2" << std::endl; 
    }
    
    if(bottle1 < bottle3){
        std::cout << "Bottle1 < Bottle3" << std::endl;  
    }
    
    if(bottle2 < bottle1){
        std::cout << "Bottle2 < Bottle1" << std::endl; 
    }
    
    if(bottle2 < bottle3){
        std::cout << "Bottle2 < Bottle3" << std::endl;  
    }
    
    // Prove the > operator 
    if(bottle1 > bottle2){
        std::cout << "Bottle1 > Bottle2" << std::endl;  
    }
    
    if(bottle1 > bottle3){
        std::cout << "Bottle1 > Bottle3" << std::endl;  
    }

    if(bottle2 > bottle1){
        std::cout << "Bottle2 > Bottle1" << std::endl;  
    }

    if(bottle2 > bottle3){
        std::cout << "Bottle2 > Bottle3" << std::endl;  
    }

    // Prove the != operator 
    if(bottle1 != bottle2){
        std::cout << "Bottle1 != Bottle2" << std::endl; 
    }
    
    if(bottle1 != bottle3){
        std::cout << "Bottle1 != Bottle3" << std::endl;  
    }
    
    if(bottle2 != bottle1){
        std::cout << "Bottle2 != bottle1" << std::endl; 
    }
    
    if(bottle2 != bottle3){
        std::cout << "Bottle2 != Bottle3" << std::endl;  
    }
    
    // Prove the == operator 
    if(bottle1 == bottle2){
        std::cout << "Bottle1 == Bottle2" << std::endl;  
    }
    
    if(bottle1 == bottle3){
        std::cout << "Bottle1 == Bottle3" << std::endl;  
    }
    
    if(bottle2 == bottle1){
        std::cout << "Bottle2 == Bottle1" << std::endl;  
    }
    
    if(bottle2 == bottle3){
        std::cout << "Bottle2 == Bottle3" << std::endl;  
    }
    
    return 0;
    
}
