/****************************************
 * File name: testBottle.cpp 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the 
 * bottle class test for Project 1 - Challenge 2 
 * *************************************/

#include <iostream>
#include <fstream>

#include "../include/bottleStr.h"

/************************************************
 * Function Name: getFileStream
 * Preconditions: char*, std::ifstream&
 * Postconditions: none 
 * 
 * This function takes in a char* and creates a 
 * ifstream based on the file name. If the file 
 * does not open, the program exits. If so, it 
 * returns a created ifstream based on that file.
 * ***********************************************/
void getFileStream(char* fileName, std::ifstream& inFile){
    
    // Create ifstream and open the stream with the file
    inFile.open(fileName);
    
    // Check if the file is open.
    if (!inFile.is_open()){
        std::cerr << "File Not Found! Exiting program..." << std::endl;
        exit(-1);
    }
    
}

/************************************************
 * Function Name: dispense
 * Preconditions: Bottle& , std::string& , int& , DATE& 
 * Postconditions: none 
 * 
 * This function takes in a Bottle and a prescription (drug Name, 
 * number of pills, and the dispense date), and dispenses the pills.
 * Includes messages if the number of pills in the prescription 
 * exceeds the number of pills in the bottle passed to the function.
 * ***********************************************/
void dispense(Bottle& theBottle, std::string& tempDrugName, int& numPills, DATE& dispDate){
        if(theBottle.getName() == tempDrugName){
        // First, check is bottle is expired 
        if(theBottle.isBottleExpired(dispDate)){
            std::cout << "Bottle " << theBottle.getName();
            std::cout << " is expired as of ";
            printDate(std::cout, theBottle.getDate());
            std::cout << ". Cannot dispense pills!" << std::endl;
        }
        // Otherwise, get medication
        else{
            if(theBottle.getLotNum() < numPills){
                std::cout << "Prescription Exceeds Number of Pills in Bottle. ";
                std::cout << "Can only dispense " << theBottle.getLotNum() << " pills" << std::endl;
                theBottle.removePills(theBottle.getLotNum());
            }
            else{
                std::cout << "Sufficient stock. Currently have " << theBottle.getLotNum();
                std::cout << " " << theBottle.getName();
                std::cout << ". Dispersing " << numPills << " " << tempDrugName << std::endl;
                theBottle.removePills(numPills);
            }
			// Print out the contents of the new bottle 
            std::cout << theBottle << std::endl;
        }
    }
}

/************************************************
 * Function Name: main 
 * Preconditions: int, char**
 * Postconditions: int 
 * 
 * This is the main driver function. 
 * ***********************************************/
int main(int argc, char** argv)
{

	if( argc != 2 )
		return EXIT_FAILURE;

    // Create the initial Bottle
    DATE initialDate = createDate(2019, 1, 23); // EXP: 2019 JAN 23 
    int lot_num = 45; // 45 pills 
    std::string drugName = "Azithromycin";
    
    // Create constructors
    Bottle bottle1(drugName, lot_num, initialDate);
    Bottle bottle2;
    
	// Print the contents of both bottles to the screen.
    std::cout << bottle1 << std::endl;
    std::cout << bottle2 << std::endl;
    
    // Pass argv[1] to getFileStream in utils.h 
    std::ifstream inStream;
	getFileStream(argv[1], inStream);
    
    std::cout << std::endl;
    //
    std::string checkVal;
    while(!inStream.eof()){
        inStream >> checkVal;
        if(checkVal == "STOCK"){
            std::cout << "STOCK: ";
            inStream >> bottle2;
            std::cout << bottle2 << std::endl;
            std::cout << std::endl;
        }
        else if(checkVal == "INSPC"){
            int year, month, day;
            inStream >> year;
            inStream >> month;
            inStream >> day;
            DATE inspecDate = createDate(year, month, day);
            
            std::cout << "INSPECTION on "; 
            printDate(std::cout, inspecDate);
            std::cout << std::endl;
            
            std::cout << "For Bottle 1: ";
            bottle1.printComp(std::cout, inspecDate);
            if(bottle1.isBottleExpired(inspecDate))
                std:: cout << "Bottle 1 is expired" << std::endl;
                
            std::cout << "For Bottle 2: ";
            bottle2.printComp(std::cout, inspecDate);
            if(bottle2.isBottleExpired(inspecDate))
                std:: cout << "Bottle 2 is expired" << std::endl;
            
            std::cout << std::endl;
        }
        else if(checkVal == "SCRIP"){
            std::cout << "SCRIPT! ";
            int year, month, day, numPills;
            std::string tempDrugName;
            
            inStream >> year;
            inStream >> month;
            inStream >> day;
            inStream >> tempDrugName;
            inStream >> numPills;
            
            DATE dispDate = createDate(year, month, day);
            
            dispense(bottle1, tempDrugName, numPills, dispDate);
            dispense(bottle2, tempDrugName, numPills, dispDate);
            
            std::cout << std::endl;
        }
    }
    
    // Close the input file
    inStream.close();
    
    return 0;
}
