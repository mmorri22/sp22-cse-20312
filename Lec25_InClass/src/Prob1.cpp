#include <iostream>

class B
{
    public:
        virtual void Hello( ) const {
            std::cout << "Hello from B" << std::endl; 
        }

        virtual void IAm ( ) const{ 
            std::cout << "I am B" << std::endl;  
        }

        void GoodBye( ) const{ 
            std::cout << "Bye from B" << std::endl;  
        }
};

class D : public B{
    
    public:
        virtual void Hello ( ) const{ 
            std::cout << "Hello from D" << std::endl;  
        }

        virtual void IAm ( ) const{ 
            std::cout << "I am D" << std::endl;  
        }

        void GoodBye( ) const{ 
            std::cout << "Bye from D" << std::endl;  
        }
};

class C : public D
{
    public:
        virtual void IAm ( ) const{ 
            std::cout <<"I am C" << std::endl; 
        }

        void GoodBye( ) const{ 
            std::cout << "Bye from C" << std::endl; 
        }
};

int main ( )
{

    B *pB = new C;
    pB->Hello( );
    pB->IAm ( );
    pB->GoodBye ( );
    
    std::cout << std::endl; 
    
    D *pD = new C;
    pD->Hello( );
    pD->IAm ( );
    pD->GoodBye ( );
    
    std::cout << std::endl; 
    
    C *pC = new C;
    pC->Hello( );
    pC->IAm( );
    pC->GoodBye( );
    
    return EXIT_SUCCESS;
}

