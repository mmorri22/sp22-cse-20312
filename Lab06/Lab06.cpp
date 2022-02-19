#include <iostream>
#include <vector>
#include <string>

/************************************
 * Step 3 - Make compiler directives
 * COUT for std::cout
 * ENDL for std::endl
 * VECTOR for std::vector
 * STRING for std::string
 * SIZE_T for long unsigned int
 ************************************/



bool is_palindrome( const STRING& the_string ){
	
	SIZE_T iter_len = the_string.size();
	
	if( iter_len == 0 )
		return false;
	
	for(SIZE_T iter = 0; iter < iter_len/2; iter++){
		
		if(the_string.at(iter) != the_string.at(iter_len-iter-1) ){
			
			return false;
		}
	}
	
	return true;
}

void find( VECTOR< VECTOR<STRING> >& solutions, VECTOR<STRING>& current_partitions, const STRING& the_string ){
	
	/********************************************************
	 * Step 5-A: Write the Base Case
	 * If the string size is 0
	   * Push current partitions onto the back of solutions
	   * return
	 ********************************************************/
	
	/********************************************************
	 * Step 5-B: Writing the Recursive Case 
	 * Write the recursive case described in the lab description
	 ********************************************************/
}



VECTOR< VECTOR<STRING> > partition( const STRING& the_string ){
	
	/************************************
	 * Step 4 - Writing the recursive set up
	 * Create a templated vector of a vector of strings called solutions
	   * Formatted just like the return value in the function call
	 * Create a vector of strings called current_partition
	 * Make a call to the find function passing solutions, current_partition, and the_string 
	 * Return solutions
	 ************************************/
 
}

void print_vector( const VECTOR< VECTOR<STRING> >& print_vector, const STRING& the_string ){
	
	COUT << "Solution for " << the_string << ": ";
	
	COUT << "[";
	for( SIZE_T iter = 0; iter < print_vector.size(); ++iter ){
		
		COUT << "[ ";
		for( SIZE_T jter = 0; jter < print_vector.at(iter).size(); ++jter ){
			
			COUT << "'" << print_vector.at(iter).at(jter) << "' ";
		}
		COUT << "]";
	}
	COUT << "]" << ENDL;
}


int main(){
	
	STRING test_1 = "a";
	STRING test_2 = "ab";
	STRING test_3 = "aab";
	STRING test_4 = "aba";
	STRING test_5 = "abab";
	STRING test_6 = "ababcb";
	// STRING test_7 = "aababcbabcbccbb";
	
	// Tests
	print_vector( partition(test_1), test_1 );
	print_vector( partition(test_2), test_2 );
	print_vector( partition(test_3), test_3 );
	print_vector( partition(test_4), test_4 );
	print_vector( partition(test_5), test_5 );
	print_vector( partition(test_6), test_6 );
	// print_vector( partition(test_7), test_7 );

	return EXIT_SUCCESS;
	
}