#include <iostream>
#include <cstdlib>

typedef struct vector{
    
    private:
        long unsigned int length;
        long unsigned int capacity;
        int* array;
        
        
    public:
    
        // Default constructor
        vector() : length(0), capacity(0), array( NULL ) {
			
			std::cout << "Base address    : " << this << std::endl;
			std::cout << "length address  : " << &(this->length) << std::endl;
			std::cout << "capacity address: " << &(this->capacity) << std::endl;
			std::cout << "array address   : " << &(this->array) << std::endl;
		}
        
        // Overloaded Constructor 
        vector( const long unsigned int& init_len ) :
            length( init_len ), capacity( init_len ), array( new int[init_len] ) {
				
			std::cout << "Base address    : " << this << std::endl;
			std::cout << "length address  : " << &(this->length) << std::endl;
			std::cout << "capacity address: " << &(this->capacity) << std::endl;
			std::cout << "array address   : " << &(this->array) << std::endl;			
				
		}
        
		// Destructor
        ~vector(){
            
			// Dr. Morrison's Golden Rule of Pointers
            if( array != NULL ){
                delete [] array;
            }
        }
		
		long unsigned int get_length(){
			
			return length;
		}
		
		long unsigned int get_capacity(){
			
			return capacity;
		}
    
}vector;

int main()
{
    
	std::cout << "Creating the empty_vec struct: " << std::endl;
    vector* empty_vec = new vector();

	std::cout << "Base register address: " << &empty_vec << ", and data heap: " << (void *)empty_vec << std::endl;

 
	std::cout << std::endl << "Creating the non_empty_vec struct: " << std::endl; 
    vector* non_empty_vec = new vector( 10 );
	std::cout << "Base register address: " << &non_empty_vec << ", and data heap: " << (void *)non_empty_vec << std::endl;
	
	std::cout << "empty_vec info: " << empty_vec->get_length() << " " << empty_vec->get_capacity() << std::endl;
	
	std::cout << "non_empty_vec info: " << non_empty_vec->get_length() << " " << non_empty_vec->get_capacity() << std::endl;
	
	delete empty_vec;
	
	delete non_empty_vec;

    return 0;
}