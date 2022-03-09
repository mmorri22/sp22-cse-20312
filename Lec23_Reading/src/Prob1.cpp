#include <iostream>
#include <fstream>

#define CIN std::cin
#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream


int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob1.txt" );
	
	while( true ) {

		COUT << "Problem 1: Given a B-Tree with a Max Degree of 4, as well as the following insertions and deletions, select the final B-Tree." << ENDL;
		COUT << ENDL;
		COUT << "Insertions: 1, 10, 2, 9, 3, 8, 4, 7, 5, 6" << ENDL;
		COUT << "Deletions: 8, 4" << ENDL << ENDL;
		
		COUT << "Review the diagrams at https://yld.me/bUg for the solution" << ENDL << ENDL;
		
		COUT << "A: See diagram" << ENDL;
		COUT << "B: See diagram" << ENDL;
		COUT << "C: See diagram" << ENDL;
		COUT << "D: See diagram" << ENDL << ENDL;
		COUT << ENDL;
		
		char stu_answer;
		
		COUT << "Enter your choice (Like Linux, answer is case sensitive): ";
		CIN >> stu_answer;
		
		if( stu_answer == 'C' ){
			COUT << "Correct Answer!" << ENDL;
			COUT << "30/30 towards Lecture 22 assignment" << ENDL;
			break;
		}
		
		else{
			COUT << "Incorrect choice. Please try again." << ENDL;
		}
		
	}

	file_out << "Student successfully answered Problem 1 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	
}
