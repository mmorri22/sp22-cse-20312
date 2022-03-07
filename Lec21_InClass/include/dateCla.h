/****************************************
 * File name: dateCla.h 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for the date 
 * using a class
 * *************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

// A string will the alphanumeric characters for the months 
const std::string MONTHS[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", 
                              "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

class DATE{
	
	private:
		int year;
		int month;
		int day;
	
	public:

		/***********************************************
		 * Function Name: DATE()
		 * Preconditions: none  
		 * Postconditions: constructed DATE object 
		 * 
		 * Empty Constructor.
		 * *********************************************/
		DATE();

		/***********************************************
		 * Function Name: DATE
		 * Preconditions: int, int, int   
		 * Postconditions: constructed DATE object 
		 * 
		 * Constructs a date based on input year, month, and day
		 * *********************************************/		
		DATE(const int& year, const int& month, const int& day);

		/***********************************************
		 * Function Name: getYear
		 * Preconditions: none
		 * Postconditions: int&
		 * 
		 * Returns the value of the DATE's year
		 * *********************************************/			
		int& getYear();

		/***********************************************
		 * Function Name: getMonth
		 * Preconditions: none
		 * Postconditions: int&
		 * 
		 * Returns the value of the DATE's month
		 * *********************************************/	
		int& getMonth();

		/***********************************************
		 * Function Name: getDay
		 * Preconditions: none
		 * Postconditions: int&
		 * 
		 * Returns the value of the DATE's day
		 * *********************************************/	
		int& getDay();

		/***********************************************
		 * Function Name: setYear
		 * Preconditions: int&
		 * Postconditions: none 
		 * 
		 * Sets the value of the DATE's year
		 * *********************************************/			
		void setYear(const int& setYear_in) ;

		/***********************************************
		 * Function Name: setMonth
		 * Preconditions: int&
		 * Postconditions: none 
		 * 
		 * Set the value of the DATE's month
		 * *********************************************/	
		void setMonth(const int& setMonth_in);

		/***********************************************
		 * Function Name: setDay
		 * Preconditions: int&
		 * Postconditions: none 
		 * 
		 * Sets the value of the DATE's day
		 * *********************************************/	
		void getDay(const int& setDay_in);
		
		/***********************************************
		 * Function Name: operator< 
		 * Preconditions: DATE& 
		 * Postconditions: bool 
		 * 
		 * This function prints the date to the user 
		 * including an alphanumeric month.
		 * Note: The month is off by one, so subtraction is 
		 * performed to get the correct alphanumeric character 
		 * *********************************************/
		bool operator<(DATE &checkDate);
		
		/***********************************************
		 * Function Name: operator>= 
		 * Preconditions: DATE& 
		 * Postconditions: bool 
		 * 
		 * This function brings in a date, and indicates if the 
		 * date is >= than the expiration Date.
		 * If it returns true, the bottle has expired
		 * *********************************************/
		bool operator>=(DATE &checkDate);
		
		/***********************************************
		 * Function Name: operator>= 
		 * Preconditions: DATE& 
		 * Postconditions: bool 
		 * 
		 * This function brings in a date, and indicates if the 
		 * date is >= than the expiration Date.
		 * If it returns true, the bottle has expired
		 * *********************************************/
		bool operator<=(DATE &checkDate);
		
		/***********************************************
		 * Function Name: operator< 
		 * Preconditions: DATE& 
		 * Postconditions: bool 
		 * 
		 * This function prints the date to the user 
		 * including an alphanumeric month.
		 * Note: The month is off by one, so subtraction is 
		 * performed to get the correct alphanumeric character 
		 * *********************************************/
		friend std::ostream& operator<<(std::ostream& out, DATE &theDate){
			
			out << theDate.getYear() << " " << MONTHS[theDate.month-1]
				<< " " << theDate.getDay();
				
			return out;
		}
	
};

#endif 