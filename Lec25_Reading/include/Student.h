#ifndef STUDENT_H
#define STUDENT_H

#include "Irish.h"

enum CLASS {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

class Student : public Irish{
	
	private:
		CLASS stuClass;
		std::string dorm;
		
		std::string getCLASS() const;
	
	public:
	
		Student(std::string lastIn, std::string firstIn, unsigned int ndIDIn, CLASS classIn);
		
		~Student();
		
		void setDorm(std::string dormIn);
		
		void printInformation();
		
		friend std::ostream& operator<<(std::ostream& output, const Student& theStudent);
	
};

#endif