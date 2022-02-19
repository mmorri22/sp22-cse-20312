#include <iostream>
#include <string>
#include <unordered_map>

#define SIZE_T long unsigned int

// Pass by reference so we don't make a copy of the string, just an abstractd pointer
void is_permutation( const std::string& the_string ){
    
    // Create the Hash
    std::unordered_map< char, int > palindrome_hash;
    
    // Set the number of odd characters
    int num_odd_chars = 0;
    
    // Iterate through the entire string
    for( SIZE_T iter = 0; iter < the_string.size(); ++iter ){
        
        // If the character is *not* a key in the hash
        if( palindrome_hash.count( the_string.at( iter ) ) == 0 ){
            
            // Insert the key in the location in the Hash
            palindrome_hash.insert( { the_string.at( iter ) , 1} );
            
            // Since it is 1, increment the number of odd characters 
            ++num_odd_chars;
        }
        else{

            // Increment the value at the specified key
            palindrome_hash[ the_string.at( iter ) ]++;
            
            // If the updated value at the specified key is even
            if( palindrome_hash[ the_string.at( iter ) ] % 2 == 0 )
            
                // Decrement the number of odd characters
                --num_odd_chars;
                
            // Otherwise, increment the number of odd characters
            else
                ++num_odd_chars;
        }
    }
    
    std::cout << "The string " << the_string << " is ";
    
    if( num_odd_chars > 1 )
        std::cout << "not ";
        
    std::cout << "a valid palindromic permutation." << std::endl;
   
}

int main()
{
    std::string test_0 = "a";
    is_permutation( test_0 );
    
    std::string test_1 = "abbacabcaddab";
    is_permutation( test_1 );
    
    std::string test_2 = "abbacabfcaddab";
    is_permutation( test_2 );
    
    std::string test_3 = "abcdcba";
    is_permutation( test_3 );

    std::string test_4 = "ab";
    is_permutation( test_4 );

    return 0;
}