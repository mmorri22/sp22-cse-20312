/****************************************
 * File name: date.h 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the date 
 * using a struct
 * *************************************/

#ifndef DATE_H
#define DATE_H

// A string will the alphanumeric characters for the months 
const std::string MONTHS[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", 
                              "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

/*******************************************
 * Struct Name: DATE
 * 
 * This struct contains the values for the 
 * year, month, and day for a date 
 * ****************************************/
typedef struct{
    int year;
    int month;
    int day;
}DATE;

/***********************************************
 * Function Name: printDate 
 * Preconditions: std::ostream& , DATE
 * Postconditions: None 
 * 
 * This function prints the date to the user 
 * including an alphanumeric month.
 * Note: The month is off by one, so subtraction is 
 * performed to get the correct alphanumeric character 
 * *********************************************/
void printDate(std::ostream& out, DATE theDate){
    out << theDate.year 
        << " " << MONTHS[theDate.month-1]
        << " " << theDate.day;
}

/***********************************************
 * Function Name: isDateLater 
 * Preconditions: DATE&, DATE&
 * Postconditions: None 
 * 
 * This function prints the date to the user 
 * including an alphanumeric month 
 * *********************************************/
bool isDateLater(DATE &initialDate, DATE &checkDate){
    
    if(checkDate.year > initialDate.year) {
        return true;
    }
    else if(checkDate.year == initialDate.year){
        if(checkDate.month > initialDate.month) {
            return true; 
        }
        else if(checkDate.month == initialDate.month){
            if(checkDate.day >= initialDate.day){
                return true;
            }
        }
    }
    return false;
    
}

/***********************************************
 * Function Name: createDate 
 * Preconditions: int, int, int 
 * Postconditions: DATE  
 * 
 * This function creates a date based on an input 
 * year, month, and date.
 * *********************************************/
DATE createDate(int year, int month, int day){
    DATE theDate;
    theDate.year = year;
    theDate.month = month;
    theDate.day = day;
    return theDate;
}

#endif 