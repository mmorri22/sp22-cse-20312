#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define COUT std::cout 
#define ENDL std::endl
#define VECTOR std::vector 
#define SET std::set
#define SIZE_T long unsigned int

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
    
    // One crucial aspect - Sorting by first element 
    SET< VECTOR<int>, decltype(&comparator) > sorted_buildings(&comparator);
    SET< VECTOR<int>, decltype(&comparator) > set_solutions(&comparator);
    
    for( VECTOR<int>& curr_building : buildings ){
        
        sorted_buildings.insert( curr_building );
        
    }
    
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
    
    // Now we update the current largest building  
    int curr_largest = final_solution.at(0).at(1);
    
    // We also know the last building will end with a 0
    for( SIZE_T iter = 1; iter < final_solution.size() - 1; ++iter ){
        
        if( final_solution.at(iter).at(1) > curr_largest )
            curr_largest = final_solution.at(iter).at(1);
        
        // If the value is greater than 0, then it is a right 
        if( final_solution.at(iter).at(1) == 0 ){
            
            if( final_solution.at(iter + 1).at(1) == 0 ){
                
                final_solution.at(iter).at(1) = final_solution.at(iter-1).at(1);
                final_solution.at(iter-1).at(1) = curr_largest;
                
                curr_largest = final_solution.at(iter).at(1);
            }
            else{
                
                curr_largest = 0;
            }
        }
    }
    
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