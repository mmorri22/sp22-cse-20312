#include <iostream>
#include <cstdlib>

template< typename T >
struct vector{
    
    private:
        long unsigned int length;
        long unsigned int capacity;
        T* array;
        
        
    public:
    
        // Default constructor
        vector() : length(0), capacity(0), array( NULL ) { }
        
        // Overloaded Constructor 
        vector( const long unsigned int& init_len ) :
            length( 0 ), capacity( init_len ), array( new T[init_len] ) { }
        
		// Destructor
        ~vector(){
            
			// Dr. Morrison's Golden Rule of Pointers
            if( array != NULL ){
                delete [] array;
            }
        }
		
		void push_back( const T& insert_val ){
			
			// Dr. Morrison's Golden Rule of Pointers 
			if( this->array == NULL ){
				
				// Set the capacity to 1
				this->capacity = 1;
				
				// Allocate an array of one integer 
				this->array = new T[ 1 ];
				
			}
			
			// Next, check if the length is equal to the capacity 
			if( this->length == this->capacity ){
				
				// If so, we need to reallocate 
				// First, multiply the capacity by 2
				this->capacity *= 2;
				
				// Then we need to create a pointer to the current array 
				T* temp = this->array;
				
				// Allocate a new vector that is length of the capacity 
				this->array = new T[ capacity ];
				
				// Iterate through the array and copy the old values to the new values 
				long unsigned int iter;
				for( iter = 0; iter < this->length; ++iter ){
					
					this->array[iter] = temp[iter];
					
				}
				
				// Finally, free the old array. Use [] to delete an array in C++
				delete [] temp;
				
			}
			
			// Insert the element at the location of length 
			this->array[ this->length ] = insert_val;
			
			// And increment the length 
			++(this->length);
			
		}
		
		long unsigned int get_length(){
			
			return length;
		}
		
		long unsigned int get_capacity(){
			
			return capacity;
		}
		
		void print_vector(){
			
			for( long unsigned int iter = 0; iter < length; ++iter ){
				
				std::cout << this->array[iter] << " ";
				
			}
			std::cout << std::endl;
		}
    
};

int main( const int argc, const char* argv[] )
{
	
    
	std::cout << "Creating the empty_vec struct: " << std::endl;
    vector<int>* empty_vec = new vector<int>();
	
	// Push the elements into the array 
	for( int iter = 1; iter < argc; ++ iter ){
		
		int temp = atoi( argv[iter] );
		
		empty_vec->push_back( temp );
	}

	// Print the contents of the empty vector
	empty_vec->print_vector();
 
	std::cout << std::endl << "Creating the non_empty_vec struct: " << std::endl; 
    vector< std::string >* non_empty_vec = new vector<std::string>( 10 );
	
	non_empty_vec->push_back( "Cheer," );
	non_empty_vec->push_back( "cheer" );
	non_empty_vec->push_back( "for" );
	non_empty_vec->push_back( "Old" );
	non_empty_vec->push_back( "Notre" );
	non_empty_vec->push_back( "Dame." );
	non_empty_vec->push_back( "Wake" );
	non_empty_vec->push_back( "up" );
	non_empty_vec->push_back( "the" );
	non_empty_vec->push_back( "echoes" );
	non_empty_vec->push_back( "cheering" );
	non_empty_vec->push_back( "her" );
	non_empty_vec->push_back( "name" );
	
	// Print the contents of the non_empty_vec
	non_empty_vec->print_vector();
	
	
	// Free the dynamically allocated memory
	delete non_empty_vec;
	delete empty_vec;

    return 0;
}