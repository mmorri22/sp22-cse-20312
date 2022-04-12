#include "../include/Student.h"


Student::Student(std::string lastIn, std::string firstIn, unsigned int ndIDIn, CLASS classIn) 
	: 	Irish(lastIn, firstIn, ndIDIn), 
		stuClass(classIn), 
		dorm("") {
			
	
	std::cout << "Base Address of Student object: " << this << std::endl;
}


Student::~Student(){
	std::cout << "Destroying Derived Class Student" << std::endl;
}	

std::string Student::getCLASS() const{
	
	switch(stuClass){
		
		case FRESHMAN:
			return "Freshman";
			break;
			
		case SOPHOMORE:
			return "Sophomore";
			break;
			
		case JUNIOR:
			return "Junior";
			break;
			
		case SENIOR:
			return "Senior";
			break;
			
		default:
			return "No valid class value";
		
	}
}
	
void Student::setDorm(std::string dormIn){
	
	dorm = dormIn;
}

std::ostream& operator<<(std::ostream& output, const Student& theStudent){
	
	output << "Student: " << theStudent.lastName << ", " << theStudent.firstName;
	output	<< " (" << theStudent.ndID << ")" << (char)10;
	output << "Home Address: " << theStudent.homeAddress << "\n";
	output << "Class Rank: " << theStudent.getCLASS() << std::endl;
	output << "Dorm: " << theStudent.dorm;
	
	return output;
}

void Student::printInformation(){
	
	// Print members derived from base class 
	std::cout << "Student: " << this->lastName << ", " << this->firstName;
	std::cout	<< " (" << this->ndID << ")" << (char)10;
	std::cout << "Home Address: " << this->homeAddress << "\n";
	
	// No need for this-> since getCLASS and dorm are not derived
	std::cout << "Class Rank: " << getCLASS() << std::endl;
	std::cout << "Dorm: " << dorm << std::endl;
	
}
