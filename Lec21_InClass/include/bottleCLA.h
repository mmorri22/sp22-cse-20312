/****************************************
 * File name: bottleCLA.h 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the 
 * bottle class for the Project 1 Pharmacy Simulator
 * *************************************/

#ifndef BOTTLE_H
#define BOTTLE_H

// Include 
#include "dateCla.h"

class Bottle{
    
    private:
        // Drug name 
        std::string drugName;
		
        // Lot number
        int lot_num;
		
        // Expiration Date 
        DATE expr_date;
    
    public:

        /**************************************
         * Function Name: Bottle
         * Pre-conditions: std::string, int, DATE 
         * Post-conditions: none 
         * 
         * This is the constructor for the Bottle class
         * ***********************************/
        Bottle(std::string drugName_in, int lot_num_in, DATE expr_date_in) : 
            drugName(drugName_in), lot_num(lot_num_in), expr_date(expr_date_in){};
         
        /**************************************
         * Function Name: Bottle
         * Pre-conditions: none 
         * Post-conditions: none 
         * 
         * This is the default constructor
         * ***********************************/
         Bottle() : drugName("No Name"), lot_num(0), expr_date(DATE(1,1,2019)){
         }
        
        // RULE OF THREE FUNCTIONS  

        /**************************************
         * Function Name: ~Bottle 
         * Pre-conditions: none 
         * Post-conditions: none 
         * 
         * This function is the class destructor 
         * ***********************************/
        ~Bottle(){}
        
        /**************************************
         * Function Name: Bottle
         * Pre-conditions: const Bottle &b 
         * Post-conditions: none 
         * 
         * This function is the copy constructor
         * ***********************************/
         Bottle(const Bottle& b){
            // Copy Drug Name 
            expr_date = b.expr_date;
        
            // Copy Lot number
            lot_num = b.lot_num;
        
            // Copy Drug name 
            drugName = b.drugName;
        }
        
        /***********************
        * Function Name: operator=
        * Preconditions: const Bottle& 
        * Postconditions: Bottle&
        * This is the IntVec assignment operator
        * *********************/
        Bottle& operator=(const Bottle& b) {
            // Copy Drug Name 
            expr_date = b.expr_date;
        
            // Copy Lot number
            lot_num = b.lot_num;
        
            // Copy Drug name 
            drugName = b.drugName;
            return *this;
        }
        
        // ACCESSOR FUNCTIONS 
        
        /**************************************
         * Function Name: getName
         * Pre-conditions: none 
         * Post-conditions: std::string&
         * 
         * Returns the address of the drugName
         * ***********************************/            
        std::string& getName(){
            return drugName;
        }

        /**************************************
         * Function Name: getLotNum
         * Pre-conditions: none 
         * Post-conditions: int&
         * 
         * Returns the number of pills
         * ***********************************/         
        int& getLotNum(){
            return lot_num;
        }
        
        /**************************************
         * Function Name: getDate
         * Pre-conditions: none
         * Post-conditions: DATE&
         * 
         * Returns the expiration date
         * ***********************************/
        DATE& getDate(){
            return expr_date;
        }

        /**************************************
         * Function Name: removePills
         * Pre-conditions: int& 
         * Post-conditions: none
         * 
         * Removes the number of pills passed
         * by the integer
         * ***********************************/          
        void removePills(int& numPills){
            lot_num -= numPills;
        }
        
        /**********************************************
         * Function Name:  isBottleExpired
         * Pre-conditions: DATE&
         * Post-conditions: bool  
         * 
         * Takes in the current date, and checks to see if 
         * the date in the bottle class is previous. Returns 
         * true if the bottle is expired. Otherwise, false.
         * ********************************************/ 
        bool isBottleExpired(DATE& checkDate){
            return checkDate >= expr_date;
        }

        /**********************************************
         * Function Name:  printComp
         * Pre-conditions: std::ostream&, DATE&
         * Post-conditions: bool  
         * 
         * Takes in the current date, and checks to see if 
         * the date in the bottle class is previous. Returns 
         * true if the bottle is expired. Otherwise, false.
         * ********************************************/         
        void printComp(std::ostream& out, DATE& checkDate){
            out << "The check date " << checkDate << " is";
    
            if(isBottleExpired(checkDate))
                out << " the same day or after ";
            else
                out << " before ";
    
            out << "the initial date " << expr_date  << std::endl;
        }

        /**********************************************
         * Function Name:  operator<<
         * Pre-conditions: std::ostream& , Bottle& 
         * Post-conditions: std::ostream& 
         * 
         * This is the overloaded << operator function
         * ********************************************/        
        friend std::ostream& operator<< (std::ostream& stream, Bottle& theBottle){
            
            stream   << theBottle.drugName << ". Pills = " << theBottle.lot_num << ". ";
            stream << "EXP: " << theBottle.expr_date;
            
            return stream;
        }

        /**********************************************
         * Function Name:  operator>>
         * Pre-conditions: std::istream& , Bottle& 
         * Post-conditions: std::ostream& 
         * 
         * This is the overloaded << operator function
         * ********************************************/        
        friend std::istream& operator>> (std::istream& stream, Bottle& theBottle){
            
			// Input drug Name 
            stream >> theBottle.drugName;
            
			// Input number 
            stream >> theBottle.lot_num;
            
			// Input Year 
            stream >> theBottle.expr_date.getYear();
            
			// Input Month
            stream >> theBottle.expr_date.getMonth();
            
			// Input Day
            stream >> theBottle.expr_date.getDay();
            
            return stream;
        }
    
};

#endif
