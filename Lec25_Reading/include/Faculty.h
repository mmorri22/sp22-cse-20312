#ifndef FACULTY_H
#define FACULTY_H

#include "Irish.h"

enum TRACK{ TENURE, TEACHING };

class Faculty : public Irish{
	
	private:
		TRACK facTrack;
		std::string dept;
		
		std::string getTRACK() const;
	
	public:
	
		Faculty(std::string lastIn, std::string firstIn, unsigned int ndIDIn, TRACK trackIn);
		
		~Faculty();
		
		void setDept(std::string deptIn);
		
		void printInformation();
		
		friend std::ostream& operator<<(std::ostream& output, const Faculty& theFaculty);
	
};

#endif
