/*******************************************************
 * File Name: dateCla.cpp 
 * Author Name: Matthew Morrison
 * E-mail: matt.morrison@nd.edu
 *
 * This file contains a sample solution for Challenge 1 
 * Part 1 where the Date is a class in "dateCla.h:
 *******************************************************/

#include "../include/dateCla.h"  // Contains Date Struct
 
DATE::DATE() : year(2000), month(1), day(1) {
 
}
 
DATE::DATE(const int& year_in, const int& month_in, const int& day_in) 
	: year(year_in), month(month_in), day(day_in) {
 
}

int& DATE::getYear(){
	return year;
}

int& DATE::getMonth(){
	return month;
}

int& DATE::getDay(){
	return day;
}
	
void DATE::setYear(const int& setYear_in){
	year = setYear_in;
}
	
void DATE::setMonth(const int& setMonth_in){
	month = setMonth_in;
}
	
void DATE::getDay(const int& setDay_in){
	day = setDay_in;
}

bool DATE::operator<(DATE &checkDate){
	if(year < checkDate.year) {
		return true;
	}
	else if(year == checkDate.year){
		if(month < checkDate.month) {
			return true; 
		}
		else if(month == checkDate.month){
			if(day < checkDate.day){
				return true;
			}
		}
	}
	return false;
}

bool DATE::operator>=(DATE &checkDate){
	if(year > checkDate.year) {
		return true;
	}
	else if(year == checkDate.year){
		if(month > checkDate.month) {
			return true; 
		}
		else if(month == checkDate.month){
			if(day >= checkDate.day){
				return true;
			}
		}
	}
	return false;
}

bool DATE::operator<=(DATE &checkDate){
	if(year < checkDate.year) {
		return true;
	}
	else if(year == checkDate.year){
		if(month < checkDate.month) {
			return true; 
		}
		else if(month == checkDate.month){
			if(day <= checkDate.day){
				return true;
			}
		}
	}
	return false;
}