#include <iostream>

class A
{
    protected:
        int val;

    public:
        virtual void Foo( ){ 
            std::cout << "A in Foo!" << std::endl; 
        }

        void Bar( ){ 
            std::cout << "A in Bar!" << std::endl; 
        }
};

class B : public A
{
    public:
        void Bar( ){ 
            std::cout << "B in Bar!" << std::endl;
        }
};

class C : public B
{
    public:
        virtual void Foo( ){ 
            std::cout << "C in Foo!" << std::endl; 
        }

        void Bar( ){ 
            std::cout << "C in Bar!" << std::endl; 
        }
};

class D : public A
{
   public:
      virtual void Foo( ){ 
          std::cout << "D in Foo!" << std::endl; 
      }
};

void test( B* b ){
   b->Foo();
}

int main ( )
{

    A *a1 = new B;      // Line 53
    test( a1 );         // Line 54
    
    C *c1 = new C;      // Line 56
    test( c1 );         // Line 57
    
    A a2;               // Line 59
    a2.Foo();           // Line 60
    
    B *b1 = new A;      // Line 62
    b1.Foo();           // Line 63

    D d1;               // Line 65
    test( &d1 );        // Line 66
    
    A *a3 = new C;      // Line 68
    a3->Bar();          // Line 69
    
    B b2;               // Line 71
    std::cout << b2.val << std::endl;   // Line 72
    
    return 0;
}