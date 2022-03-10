#include "../include/Student.h"
#include "../include/Faculty.h"

int main(){
	
	Student freshman("Jones", "NewGuy", 920231842, FRESHMAN);
	Faculty tenure("Flynn", "Patrick", 911110796, TENURE);
	Student senior("Smith", "Julia", 920201182, SENIOR);
	Faculty teaching("Morrison", "Matthew", 911120616, TEACHING);

	senior.setHomeAddress("101 Main St., Fulton, MD, 20759");
	teaching.setHomeAddress("207 Notre Dame St., South Bend, IN, 46530");
	tenure.setHomeAddress("118A Rt 23, South Bend, IN, 46530");
	freshman.setHomeAddress("404 Sunshing Blvd, Tampa, FL, 38655");
	
	tenure.setDept("Computer Science and Engineering");
	teaching.setDept("Computer Science and Engineering");
	
	freshman.setDorm("Dillon");
	senior.setDorm("Pangborn");
	
	std::cout << freshman << std::endl << std::endl;
	std::cout << senior << std::endl << std::endl;
	std::cout << tenure << std::endl << std::endl;
	std::cout << teaching << std::endl << std::endl;
	
	return 0;
}

