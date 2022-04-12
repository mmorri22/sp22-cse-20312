#include "../include/Irish.h"

int main(){
	
	Irish student("Jones", "Student", 920201842);
	
	Irish faculty("Morrison", "Matthew", 911110796);
	
	student.setHomeAddress("101 Main St., Fulton, MD, 20759");
	faculty.setHomeAddress("207 Notre Dame St., South Bend, IN, 46530");

	std::cout << student << std::endl << std::endl;
	
	std::cout << faculty << std::endl << std::endl;
	
	return 0;
}

