#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define COUT std::cout 
#define ENDL std::endl
#define VECTOR std::vector 
#define SET std::set
#define SIZE_T long unsigned int

/***************************
 * Step 4 - Part 1 
 * Writing the comparator Function
 * Input two const integer vectors with const and call by reference 
 * The return the condition is if the first element (i.e. [0] or .at(0) 
 * in the first vector is *less* than the first element from the second vector 
 **************************/
bool comparator(const VECTOR<int> &a, const VECTOR<int> &b){
    
  return a.at(0) < b.at(0);
  
}


void print_sets( const SET< VECTOR<int>, decltype(&comparator) >& print_set  ){
    
    for( const VECTOR<int>& curr_building : print_set ){
        COUT << "[ ";
        for( const int curr_int : curr_building ){
            
            COUT << curr_int << " ";
            
        }
        COUT << "]";
    } 
    COUT << ENDL;
}


void print_vecs( const VECTOR< VECTOR<int> >& print_vec ){
    
    for( const VECTOR<int>& curr_building : print_vec ){
        COUT << "[ ";
        for( const int curr_int : curr_building ){
            
            COUT << curr_int << " ";
            
        }
        COUT << "]";
    }    
    COUT << ENDL;
    
}

VECTOR< VECTOR<int> > get_skyline(VECTOR< VECTOR<int> >& buildings) {
    
	/***************************
	 * Step 4 - Part 2 
	 * Create the two sets of integer vectors, with the comparator function 
	 * as the input for the function
	 * Put the set declarations from the Lab description here before the for loop
	 **************************/
    SET< VECTOR<int>, decltype(&comparator) > sorted_buildings(&comparator);
    SET< VECTOR<int>, decltype(&comparator) > set_solutions(&comparator);
    
    for( VECTOR<int>& curr_building : buildings ){
        
        sorted_buildings.insert( curr_building );
        
    }


	/***************************
	 * This code is the provided code described in the Lab Description
	 * in Section 5 prior to your required work.
	 **************************/    
    COUT << "Sorted Buildings: " << ENDL;
    print_sets( sorted_buildings );
    
    // Mark Key Points (Top Left and Bottom Right) for each building 
    for( const VECTOR<int>& curr_building : sorted_buildings ){
        
        VECTOR<int> first_point;
        first_point.push_back( curr_building.at(0) );
        first_point.push_back( curr_building.at(2) );
        
        VECTOR<int> second_point;
        second_point.push_back( curr_building.at(1) );
        second_point.push_back( 0 );        

        set_solutions.insert( first_point );
        set_solutions.insert( second_point );
        
        COUT << "Current Key Points Sorted in the Set:" << ENDL;
        print_sets( set_solutions );

    }
    
    // Solution Vector 
    VECTOR< VECTOR<int> > final_solution;
    
    // Put the elements from the set into the vector 
    for( const VECTOR<int>& curr_building : set_solutions ){
         
        final_solution.push_back( curr_building );
         
    }
    
	/***************************
	 * Step 5 
	 * Here, you will iterate through the sored vector final_solution 
	 * And you will set up the choices for the algorithm 
	 **************************/
  
    // First, create an integer which stores the current largest value 
	// Make that integer equal to the destination edge, which is the 
	// first *end of the building. I define the destination edge thusly:
	// final_solution.at(0).at(1) - The destination edge of the building .at(0)
	// is .at(1). So the iter's destination edge will be final_solution.at(iter).at(1)
    int curr_largest = final_solution.at(0).at(1);
    
    // Iterate through the buildings. But we will start at the second building 
	// and go until the second to last building (i.e. start at 1 and go until 
	// final_solution.size() - 1
    for( SIZE_T iter = 1; iter < final_solution.size() - 1; ++iter ){
        
		// If the iter's destination edge is greater than the current largest
        if( final_solution.at(iter).at(1) > curr_largest )
			// Update the current largest to the iter's destination edge 
            curr_largest = final_solution.at(iter).at(1);
        
        // If the iter's destination edge is equal to 0
        if( final_solution.at(iter).at(1) == 0 ){
            
			// If the (iter+1)'s destination edge is also 0 - the next building
            if( final_solution.at(iter + 1).at(1) == 0 ){
                
				// Set iter's destination edge to (iter-1)'s destination edge
                final_solution.at(iter).at(1) = final_solution.at(iter-1).at(1);
				// Set (iter-1)'s destination edge to current largest
                final_solution.at(iter-1).at(1) = curr_largest;
				// Set curren largest to iter's destination edge
                curr_largest = final_solution.at(iter).at(1);
            }
			// Else
            else{
                // We reached the end of a se of buildings. Set current largest equal to 0
                curr_largest = 0;
            }
        }
    }
    
	/*********** Part 5 Ends Here **********/
    
    COUT << "Vector Prior to Final Pruning:" << ENDL;
    print_vecs( final_solution );
    
    // Finally, prune the vector 
    for( SIZE_T iter = 1; iter < final_solution.size(); ++iter ){
        
        // They are the same, so we need to prune 
        if( final_solution.at(iter).at(1) == final_solution.at(iter-1).at(1) ){
            
            final_solution.erase( final_solution.begin() + iter );
        }
    }
        
    return final_solution;
}

int main()
{
    
    // Create Buildings 
    // Inserted Deliberately Out of Order 
    VECTOR<int> building1{ 15, 20, 10 };
    VECTOR<int> building2{ 2, 9, 10 };
    VECTOR<int> building3{ 5, 12, 12 };
    VECTOR<int> building4{ 19, 24, 8 };
    VECTOR<int> building5{ 3, 7, 15 };
    
    // Create Buildings 
    VECTOR< VECTOR<int> > buildings {building1, building2, building3, building4, building5};
    
    // Print initial set 
    COUT << "Initial Unsorted Buildings:" << ENDL;
    print_vecs( buildings );
    
    VECTOR< VECTOR<int> > solution = get_skyline( buildings );
    
    COUT << "Final Solution:" << ENDL;
    print_vecs( solution );

    return 0;
}