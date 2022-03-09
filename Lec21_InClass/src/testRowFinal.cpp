/****************************************
 * File name: testRowFinal.cpp 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the 
 * bottle class for the Project 1 Pharmacy Simulator
 * Part 1 - test the overlap operators for the 
 * Row (in this case, Queue) Class 
 * *************************************/

#include <iostream>
#include <fstream>

#include "../include/queueFinal.h"
#include "../include/bottleFinal.h"    // Includes "date.h"

/************************************
 * Function Name: main 
 * Preconditions: int, char**
 * Postconditions: int  
 * Main driver function creates three Rows (queues) and 
 * compares them using the >, <, ==, and != operators 
 * *********************************/
int main(const int argc, const char** argv)
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
    
    // Create the queue class 
    queue<Bottle> queue1;
    queue<Bottle> queue2;
    queue<Bottle> queue3;
    
    // Push the bottles onto the queues
    queue1.push(bottle1);
    queue2.push(bottle2);
    queue3.push(bottle3);
    
	// Print the contents of both queues to the screen.
    std::cout << "Queue1: " << queue1.peek() << std::endl;
    std::cout << "Queue2: " << queue2.peek() << std::endl;
    std::cout << "Queue3: " << queue3.peek() << std::endl;
    
    // Prove the < operator
    if(queue1 < queue2){
        std::cout << "Queue1 < Queue2" << std::endl; 
    }
    
    if(queue1 < queue3){
        std::cout << "Queue1 < Queue3" << std::endl;  
    }
    
    if(queue2 < queue1){
        std::cout << "Queue2 < Queue1" << std::endl; 
    }
    
    if(queue2 < queue3){
        std::cout << "Queue2 < Queue3" << std::endl;  
    }
    
    // Prove the > operator 
    if(queue1 > queue2){
        std::cout << "Queue1 > Queue2" << std::endl;  
    }
    
    if(queue1 > queue3){
        std::cout << "Queue1 > Queue3" << std::endl;  
    }

    if(queue2 > queue1){
        std::cout << "Queue2 > Queue1" << std::endl;  
    }

    if(queue2 > queue3){
        std::cout << "Queue2 > Queue3" << std::endl;  
    }

    // Prove the != operator 
    if(queue1 != queue2){
        std::cout << "Queue1 != Queue2" << std::endl; 
    }
    
    if(queue1 != queue3){
        std::cout << "Queue1 != Queue3" << std::endl;  
    }
    
    if(queue2 != queue1){
        std::cout << "Queue2 != queue1" << std::endl; 
    }
    
    if(queue2 != queue3){
        std::cout << "Queue2 != Queue3" << std::endl;  
    }
    
    // Prove the == operator 
    if(queue1 == queue2){
        std::cout << "Queue1 == Queue2" << std::endl;  
    }
    
    if(queue1 == queue3){
        std::cout << "Queue1 == Queue3" << std::endl;  
    }
    
    if(queue2 == queue1){
        std::cout << "Queue2 == Queue1" << std::endl;  
    }
    
    if(queue2 == queue3){
        std::cout << "Queue2 == Queue3" << std::endl;  
    }
    
    return 0;
    
}
