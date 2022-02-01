#include <iostream>
#include <cstdlib>
#include <string>

typedef struct Animal {

    public:
        std::string name;
        int age;

    private:
        int weight;

    public:
    
        // Default Constructor
        Animal( ) : name(), age(0), weight(0) {}
        
        // Overloaded Constructor 
        Animal( const std::string& name_in, const int& age_in, const int weight_in ):
            name( name_in ), age( age_in ), weight( weight_in ) {
                
                std::cout << "Constructor Info for: " << this->name << std::endl;
                std::cout << "Base address  : " << this << std::endl;
                std::cout << "Name address  : " << &(this->name) << std::endl;
                std::cout << "Age address   : " << &(this->age) << std::endl;
                std::cout << "Weight address: " << &(this->weight) << std::endl;
            }
    
        // to allow access to the private `weight` member via methods, these need to be public
        void setWeight(int w) {
            if (w > 100) {
                std::cerr << "error: unrealistic weight!" << std::endl;
                return;
            }
            this->weight = w;
        }
    
        int getWeight() {
            return this->weight;
        }
        
        void print_Animal(){
            
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Name: " << this->name << std::endl;
            std::cout << this->name << "'s age: " << this->age << std::endl;  
            std::cout << this->name << "'s weight: " << this->weight << std::endl;   
            std::cout << "--------------------------------" << std::endl;

        }
  
} Animal;

int main()
{
    Animal stack_cat( "Garfield", 5, 10 );
    stack_cat.print_Animal();
    
    stack_cat.setWeight(12);
    stack_cat.print_Animal();    

    // C++ Equivalent of Animal* heap_dog = (Animal *)malloc( sizeof(Animal) );
    Animal* heap_dog = new Animal( "Eirinn", 7, 55);
    heap_dog->print_Animal();
    
    heap_dog->setWeight(999); // will report an error
    
    
    // C++ Equivalent of free( heap_dog );
    delete heap_dog;
    
    return EXIT_SUCCESS;
}