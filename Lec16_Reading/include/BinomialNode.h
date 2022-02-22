#ifndef BINOMIALNODE_H
#define BINOMIALNODE_H

#include <iostream>
#include <stdexcept>

template< typename T >
struct BinomialNode
{
	T data;	// Data itself
	BinomialNode<T>* leftChild;		// Node's left child
	BinomialNode<T>* nextSibling;	// Node's next sibling
	
	// Constructor
	BinomialNode( const T& dataIn ) : leftChild( NULL ), nextSibling( NULL ) { }
	
	~BinomialNode() {   }
	
	// Copy Constructor
	BinomialNode( const BinomialNode<T>& copy ) : data(copy.data), 
		leftChild( clone( copy.leftChild ) ), nextSibling( clone( copy.nextSibling ) ) { }
	
	// Assignment Operator
	BinomialNode<T> operator=( const BinomialNode<T>& assign ){ 
	
		if( this != &assign ){
			this->data = assign.data;
			this->leftChild = clone( assign.leftChild );
			this->nextSibling = clone( assign.nextSibling );
		}
		return *this;
	}

	// Constructor 
	BinomialNode( const T& dataIn, BinomialNode<T>* lt, BinomialNode<T>* rt )
	  : data( dataIn ), leftChild( clone(lt) ), nextSibling( clone(rt) ) { }

	// Clone a Node
    BinomialNode<T>* clone( BinomialNode<T>* t ) const
    {
        if( t == NULL )
            return NULL;
        else
			// Clone the leftChild and nextSibling
            return new BinomialNode<T>( t->data, clone( t->leftChild ), clone( t->nextSibling ) );
    }
	
	// Combine two node
    BinomialNode<T>* combineTrees( BinomialNode<T> *t1, BinomialNode<T> *t2 )
    {
		// If the second e
        if( t2->data < t1->data )
            return combineTrees( t2, t1 );
		
        t2->nextSibling = t1->leftChild;	
        t1->leftChild = t2;
        return t1;
    }
	
};

#endif