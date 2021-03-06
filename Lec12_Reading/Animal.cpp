#include <iostream>
#include <cstdlib>
#include <string>

typedef struct Animal {

        std::string name;
        int age;
        int weight;
       
    
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
    Animal stack_cat;
	stack_cat.name = "kitty";
	stack_cat.age = 5;
    stack_cat.setWeight(12);
    stack_cat.print_Animal();    

    // C++ Equivalent of Animal* heap_dog = (Animal *)malloc( sizeof(Animal) );
    Animal* heap_dog = new Animal();
	heap_dog->name = "Eirinn";
	heap_dog->age = 7;
	heap_dog->setWeight(55);
	
    heap_dog->print_Animal();
    
    heap_dog->setWeight(999); // will report an error
    
    
    // C++ Equivalent of free( heap_dog );
    delete heap_dog;
    
    return EXIT_SUCCESS;
}