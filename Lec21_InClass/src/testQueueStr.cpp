/****************************************
 * File name: testQueueStr.cpp 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the 
 * bottle class test for Project 1 - Challenge 2 
 * for when the Date is a struct 
 * *************************************/

#include <iostream>
#include <fstream>

#include "../include/queue.h"
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
void getFileStream(char* fileName, std::ifstream &inFile){
    
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
 * Preconditions: queue<Bottle>& , std::string& , int& , DATE& 
 * Postconditions: none 
 * 
 * This function takes in a Bottle and a prescription (drug Name, 
 * number of pills, and the dispense date), and dispenses the pills.
 * Includes messages if the number of pills in the prescription 
 * exceeds the number of pills in the bottle passed to the function.
 * ***********************************************/
void dispense(queue<Bottle>& theBottle, std::string& tempDrugName, int& numPills, DATE& dispDate){
    
    if(theBottle.empty()){
        std::cout << "The row is empty, and the medication cannot be dispersed" << std::endl;
        return;
    }
    
    if(theBottle.peek().getName() == tempDrugName){
        
        // Continue to check bottles while the row isn't empty and pills still need to be dispensed
        while(!theBottle.empty() && numPills > 0){
            
            // First, check if the pills in the front are expired
            if(theBottle.peek().isBottleExpired(dispDate)){
                std::cout << "Front bottle " << theBottle.peek().getName();
                std::cout << " is expired as of ";
                printDate(std::cout, theBottle.peek().getDate());
                std::cout << ". Removed from row!" << std::endl;
                
                // Remove the bottle from the front 
                theBottle.pop();
            }
            
            // Otherwise, get the pills from the bottle 
            else{
                std::cout << "Front bottle of " << tempDrugName << " not expired and has pills." << std::endl;
                if(theBottle.peek().getLotNum() < numPills){
                    std::cout << "Prescription Exceeds Number of Pills in Bottle. ";
                    std::cout << "Can only dispense " << theBottle.peek().getLotNum();
                    std::cout << " pills from front bottle" << std::endl;
                    
                    // Subtract the number of pills that the 
                    numPills -= theBottle.peek().getLotNum();
                    
                    // Remove the empty bottle from the row.
                    theBottle.pop();
                }
                else{
                    std::cout   << "Sufficient stock in front bottle. Currently have " 
                                << theBottle.peek().getLotNum();
                    std::cout << " " << theBottle.peek().getName();
                    std::cout << ". Dispersing " << numPills << " " << tempDrugName << std::endl;
                    theBottle.peek().removePills(numPills);
                    numPills = 0;
                }
            }
            
        }
        
        if(numPills > 0){
            std::cout << "The pharmacy is out of " << tempDrugName;
            std::cout << " and the patient still needs " << numPills << std::endl;
        }
    }
    else{
        // Script is not for this row
        std::cout << "This row does not contain " << tempDrugName << std::endl;
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
    
    // Create a templated queue 
    queue<Bottle> bottleRow;
    
    // Pass argv[1] to getFileStream in utils.h 
    std::ifstream inStream; 
	getFileStream(argv[1], inStream);
    
    std::string checkVal;
    while(!inStream.eof()){
        
        inStream >> checkVal;
        
        if(checkVal == "STOCK"){
            Bottle bottleTemp;
            std::cout << "STOCK: ";
            inStream >> bottleTemp;
            
            std::cout << "Attempting to stock new bottle: " << bottleTemp << std::endl;
            
            if(bottleRow.empty()){
                bottleRow.push(bottleTemp);
                std::cout << "Successful stock!" << std::endl;
            }
            else{
                if(bottleTemp.getName() != bottleRow.peek().getName()){
                    std::cout << "This row is not for " << bottleTemp.getName();
                    std::cout << ". Cannot be stocked." << std::endl;
                }
                else{
                    bottleRow.push(bottleTemp);
                    std::cout << "Successful stock!" << std::endl;
                }
            }

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
            
            if(!bottleRow.empty()){
                
                // If the first bottle passes, you may assume the rest do as well
                if(!bottleRow.peek().isBottleExpired(inspecDate)){
                    std:: cout  << "Bottle in front of " << bottleRow.peek().getName() 
                                << " with EXP: "; 
                    printDate(std::cout, bottleRow.peek().getDate());
                    std::cout << " passes inspection!!" << std::endl;
                }
                else{
                
                    // Otherwise, need to tell user that there are expired bottles
                    while(!bottleRow.empty() && bottleRow.peek().isBottleExpired(inspecDate)){
                        bottleRow.peek().printComp(std::cout, inspecDate);
                        std:: cout << "Bottle in front of " << bottleRow.peek().getName() << " is expired" << std::endl;
                        // Pop off the most 
                        bottleRow.pop();
                        std::cout << "Bottle in Front Removed" << std::endl;
                    }
                    
                    
                    if(!bottleRow.empty()){
                        std::cout << "'" << std::endl;
                        // If the first bottle remaining, you may assume the rest do as well
                        if(!bottleRow.peek().isBottleExpired(inspecDate)){
                            std:: cout  << "Bottle in front of " << bottleRow.peek().getName() 
                                << " with EXP: "; 
                            printDate(std::cout, bottleRow.peek().getDate());
                            std::cout << " passes inspection!!" << std::endl;
                        }
                    }
                    else{
                        std::cout << "Row is now empty! No more bottles to inspect." << std::endl;
                    }
                }
            }
            else{
                std::cout << "Row is empty! No bottles to inspect." << std::endl;
            }
        }
        
        // Provide a prescription.
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
            
            std::cout << "Patient brought in a prescription on ";
            printDate(std::cout, dispDate);
            std::cout << " for "<< numPills << " " << tempDrugName << std::endl;
            
            dispense(bottleRow, tempDrugName, numPills, dispDate);
            
        }
        
        
        std::cout << std::endl;
    }
    
    std::cout << "THE END!!!" << std::endl;
    
    // Close the input file
    inStream.close();
    
    return 0;
}