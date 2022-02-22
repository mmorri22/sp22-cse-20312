#include "../include/PriorityQueue.h"
#include "../include/Priority.h"

#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Initialize the Priority Queue with string Priorities
	PriorityQueue< Priority<std::string> > thePQ;
	
	// Create the Priority Elements
	Priority< std::string > priority1("Cheering", 5);
	Priority< std::string > priority2("The", 3 );
	Priority< std::string > priority3("Name", 7);
	Priority< std::string > priority4("Wake", 1);
	Priority< std::string > priority5("Echoes", 4);
	Priority< std::string > priority6("Her", 6);
	Priority< std::string > priority7("Up", 2);
	
	// Push the Priority Elements
	thePQ.push( priority1 );	thePQ.push( priority2 );	thePQ.push( priority3 );
	thePQ.push( priority4 );	thePQ.push( priority5 );	thePQ.push( priority6 );
	thePQ.push( priority7 );
	
	// Print the results from pop
	COUT << "Priority Result: " << ENDL;
	while( !thePQ.empty() ){
		
		COUT << thePQ.front() << ENDL;
		thePQ.pop();
	}

	return 0;
}
