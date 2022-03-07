/****************************************
 * File name: testPharm.cpp 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for Project 1 
 * using a Singularly Linked List for the shelf 
 * and a queue for the bottle rows 
 * *************************************/

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "../include/bottleFinal.h"    // Includes "date.h"
#include "../include/queueFinal.h"
#include "../include/SLList.h"

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
void dispense(queue<Bottle>& theBottle, std::string& tempDrugName, int& numPills, DATE& dispDate, bool *check){
    *check = true;
    
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
                    
                    // Check if the bottle is empty
                    if(theBottle.peek().getLotNum() == 0){
                        theBottle.pop();
                        
                    // Check if the bottle just removed was the last one.
                    if(theBottle.empty())
                            *check = false;
                    }
                }
            }
            
        }
        
        if(numPills > 0){
            std::cout << "The pharmacy is out of " << tempDrugName;
            std::cout << " and the patient still needs " << numPills << std::endl;
            *check = false;
        }
    }
    else{
        // Script is not for this row
        std::cout << "This row does not contain " << tempDrugName << std::endl;
    }
}

int main(int argc, char** argv){
    
    // Create a Singularly Linked List of queues of Bottles 
    LinkedList< queue<Bottle> > thePharmacy;
    
    // Pass argv[1] to getFileStream in utils.h 
    std::ifstream inStream; 
	getFileStream(argv[1], inStream);
    
    // Get the first input 
    std::string checkVal;
    
    while(!inStream.eof()){
        
        inStream >> checkVal;
        
        // Putting the bottle on the shelf.
        if(checkVal == "STOCK"){
            
            // Create temporary bottle and row 
            Bottle bottleTemp;
            queue<Bottle> tempRow;
            
            std::cout << "STOCK: ";
            inStream >> bottleTemp;
            
            // Automatically push the bottle into the tempRow
            tempRow.push(bottleTemp);
            
            // Print the bottle to the user 
            std::cout << "Attempting to stock new bottle: " << tempRow.peek() << std::endl;
            
            // Attempt to insert the row into the LinkedList, and return the node.
            bool check;
            Node<queue<Bottle>>* temp = thePharmacy.inOrderInsert(tempRow, &check);
            
            if(check){
                std::cout << "Successful stock of new bottle type: " << tempRow.peek() << std::endl;
            }
            else{
                std::cout << "Putting bottle in existing row of " << temp->data.peek().getName() << std::endl;
                temp->data.push(tempRow.peek());
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
            
            // 
            if(thePharmacy.head->next == nullptr && thePharmacy.head != thePharmacy.tail){
                std::cout << "No medication in Pharmacy to inspect." << std::endl;
            }
            
            else{
                Node<queue<Bottle>>* current;
                Node<queue<Bottle>>* nextNode = thePharmacy.head->next;
                
                //do{ // when nextNode == nullPtr, we've reached and read the tail 
				for(current = thePharmacy.head; current != thePharmacy.tail->next;
					current = current->next){
                    
                    std::cout << "Inspecting " << current->data.peek().getName() << "..." << std::endl;
                    
                    bool deletedHeadNode = false;
                    bool deletedTailNode = false;
                    
                    // If the first bottle passes,  
                    if(!current->data.peek().isBottleExpired(inspecDate)){
                        std:: cout  << "Bottle in front of " << current->data.peek().getName() 
                                << " with EXP: "; 
                        printDate(std::cout, current->data.peek().getDate());
                        std::cout << " passes inspection!!" << std::endl;
                    }
                    else{
                
                        // Otherwise, need to tell user that there are expired bottles
                        while(!current->data.empty() && current->data.peek().isBottleExpired(inspecDate)){
                            current->data.peek().printComp(std::cout, inspecDate);
                            std:: cout << "Bottle in front of " << current->data.peek().getName() 
                                        << " with EXP: ";
                            printDate(std::cout, current->data.peek().getDate());
                            std::cout << " is expired...";
                            // Pop off the most 
                            current->data.pop();
                            std::cout << "...Bottle in Front of Removed" << std::endl;
                        }
                        
                        if(!current->data.empty()){
                            // If the first bottle remaining, you may assume the rest do as well
                            if(!current->data.peek().isBottleExpired(inspecDate)){
                                std:: cout  << "Bottle in front of " << current->data.peek().getName() 
                                    << " with EXP: "; 
                                printDate(std::cout, current->data.peek().getDate());
                                std::cout << " passesG inspection!!" << std::endl;
                            }
							std::cout << " Hello?!!" << std::endl;
                        }
                        else{
                            
                            std::cout << "Row is now empty! No more bottles to inspect." << std::endl;
                            
                            // Remove the current node to indicate there are no more bottles 
                            // of this specific drug left in the Pharmacy.
                            if(current == thePharmacy.head){
                                deletedHeadNode = true;
                            }
                            
                            if(current == thePharmacy.tail){
                                deletedTailNode = true;
                            }
                            thePharmacy.deleteNode(current);
                        }
                    }
                    
                    if(deletedHeadNode && deletedTailNode){
                        thePharmacy.head = new Node< queue<Bottle> >();
                        thePharmacy.tail = new Node< queue<Bottle> >();
                    }
                    
                    else if(deletedHeadNode){
                        current = thePharmacy.head;
                        nextNode = thePharmacy.head->next;

                    }
				}
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
            
            if(thePharmacy.head->next == nullptr){
                std::cout << "No medication in Pharmacy. Cannot dispense any medication." << std::endl;
            }
            else{
                Node<queue<Bottle>>* current = thePharmacy.head;
                Node<queue<Bottle>>* nextNode = thePharmacy.head->next;
                
                while(current->data.peek().getName() != tempDrugName && current != thePharmacy.tail){
                    current = current->next;
                    nextNode = nextNode->next;
                }
                
                if(current->data.peek().getName() == tempDrugName){  // The 
                   std::cout << "The Pharmacy has " << tempDrugName << "in stock!" << std::endl; 
                   
                   bool check;
                   
                   // Dispense the medication!
                   dispense(current->data, tempDrugName, numPills, dispDate, &check);
                   
                   // If check is false, then the current bottle row is now empty, and we need to delete the node 
                   if(!check){
                       thePharmacy.deleteNode(current);
                   }
                }
                else{
                    std::cout << "The Pharmacy currently does not have " << tempDrugName << "in stock!" << std::endl;
                }
            }
            
        }
        
        else if(checkVal == "INVEN"){
            std::cout << "INVEN: Printing the inventory for the first bottle in each row..." << std::endl;
            
            if(thePharmacy.head->next == nullptr){
                std::cout << "No medication in Pharmacy." << std::endl;
            }
            else{
                Node<queue<Bottle>>* current = thePharmacy.head;

				for(current = thePharmacy.head; current != thePharmacy.tail->next;
					current = current->next){
					
					std::cout << current->data.peek() << std::endl;
				}
            }
        }
        
        std::cout << std::endl;
    }
    
    
    return 0;
}
