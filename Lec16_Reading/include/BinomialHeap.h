#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include <iostream>
#include <vector>
#include <cstdlib> 
#include "BinomialNode.h"

const int DEFAULT_TREES = 1;	// Set the Default Number of Trees

template < typename T >
struct BinomialHeap
{

  private:

    std::vector< BinomialNode<T>* > theTrees;  	// An array of Binomial Tree root pointers
    int currentSize;							// Number of items in the priority queue
    
	// Return the index of the Binomial Tree containing the smallest value
    int findMinIndex( ) const
    {
        int iter = 0;
        int minIndex;

        while( theTrees[ iter ] == NULL ){
            iter++;
		}

        for( minIndex = iter; iter < theTrees.size( ); iter++ ){
			
			// If the current tree isn't NULL and the data is less than the minIndex
            if( theTrees[ iter ] != NULL && theTrees[ iter ]->data < theTrees[ minIndex ]->data ){
				
				// Update the location of the minIndex
                minIndex = iter;
			}
		}

        return minIndex;
    }

    // Returns the capacity of the tree
    int capacity( ) const{ 
	
		return ( 1 << theTrees.size( ) ) - 1; 
	}

    // Combine two Binomial Nodes
    BinomialNode<T>* combineTrees( BinomialNode<T> *t1, BinomialNode<T> *t2 )
    {
        if( t2->data < t1->data )
            return combineTrees( t2, t1 );
		
        t2->nextSibling = t1->leftChild;
        t1->leftChild = t2;
		
        return t1;
    }

    // Make the node empty - Use for deletion
    void makeEmpty( BinomialNode<T>*& t )
    {
        if( t != NULL )
        {
            makeEmpty( t->leftChild );
            makeEmpty( t->nextSibling );
            delete t;
            t = NULL;
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinomialNode<T>* clone( BinomialNode<T> * t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinomialNode<T>{ t->data, clone( t->leftChild ), clone( t->nextSibling ) };
    }
	
	void printHeap( std::ostream& out, const BinomialNode<T>* printNode ){
		
		if( printNode == NULL ){
			return;
		}
		
		out << printNode->data << " ";
		
		printHeap( out, printNode->leftChild );
		printHeap( out, printNode->nextSibling );		
	}

  public:
  
    BinomialHeap( ) : theTrees( DEFAULT_TREES ), currentSize( 0 )
    {
        for( auto & root : theTrees )
            root = NULL;
    }

    BinomialHeap( const T & item ) : theTrees( 1 ), currentSize( 1 ){ 
		theTrees[ 0 ] = new BinomialNode<T>( item, NULL, NULL ); 
	}

	// Destructor 
    ~BinomialHeap( ){ 
		theTrees.clear();	// clear method in std::vector for freeing all the memory
	}
    
    // Return if the Binomial Heap does not have a current size
    bool isEmpty( ) const{ 
		return currentSize == 0; 
	}

    // Public Find Minimum Value Method
    const T& findMin( ) const
    {
        return theTrees[ findMinIndex( ) ]->data;
    }
    
    // Public Insert
    void insert( const T & x ){ 
	
		// Create a Binomial Heap with one item
		BinomialHeap<T> oneItem( x ); 
		
		// Merge with the current Binomial Heap
		merge( oneItem ); 
	}
    
    // Deletes the smallest value from the Heap
    void deleteMin( )
    {
        T x;	// x is called by reference
		deleteMin( x );
    }

    // Public Method to Delete the Smallest Item
    void deleteMin( T& minItem )
    {
		// If the Heap is empty, do nothing
		if( isEmpty( ) ){	return;	   }

		// Get the minimum item and its index
        int minIndex = findMinIndex( );
        minItem = theTrees[ minIndex ]->data;

		// Create pointer to the tree with the smallest value and its left child
        BinomialNode<T>* oldRoot = theTrees[ minIndex ];
        BinomialNode<T>* deletedTree = oldRoot->leftChild;

        // Construct H''
        BinomialHeap deletedQueue;
        deletedQueue.theTrees.resize( minIndex );
        deletedQueue.currentSize = ( 1 << minIndex ) - 1;
        for( int j = minIndex - 1; j >= 0; --j )
        {
            deletedQueue.theTrees[ j ] = deletedTree;
            deletedTree = deletedTree->nextSibling;
            deletedQueue.theTrees[ j ]->nextSibling = NULL;
        }

        // Construct H'
        theTrees[ minIndex ] = NULL;
        currentSize -= deletedQueue.currentSize + 1;
		
		// Merge the delete item (old left child) with the remaining Heap
        merge( deletedQueue );
    }

    /**
     * Make the priority queue logically empty.
     */
    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & root : theTrees )
            makeEmpty( root );
    }

	// Merge two Binomial Heaps together
    void merge( BinomialHeap<T>& rhs )
    {
        if( this == &rhs )    // Avoid aliasing problems
            return;

		// Step 1 -  we add the sizes of the Binomial Heaps
        currentSize += rhs.currentSize;

		// Step 2 - If the size of the desired merge tree is greater than the capacity
        if( currentSize > capacity( ) )
        {
			// Get the size of the oldTree and the tree we are entering
            long unsigned int oldNumTrees = theTrees.size( );
			long unsigned int newNumTrees = 1;
			
			// If the tree is greater than the right hand side
			if( theTrees.size( ) > rhs.theTrees.size( ) ){
				
				// Add the newNumTrees and the Binomial Tree size
				newNumTrees += theTrees.size( );
			}
			else{
				// Otherwise, add rhs and nuwNumTrees
				newNumTrees += rhs.theTrees.size( );
			}

			// Update the size of the Dynamic Array
            theTrees.resize( newNumTrees );
			
			// For all the new values, set the results to NULL
            for( long unsigned int i = oldNumTrees; i < newNumTrees; i++ ){
                theTrees[ i ] = NULL;
			}
        }

		// Create a node for carry's the values 
        BinomialNode<T>* carry = NULL;
		
		// Iterate through all the nodes
        for( int i = 0, j = 1; j <= currentSize; i++, j *= 2 )
        {
			// Create two temporary nodes 
			
			// The first is the current temp 
            BinomialNode<T>* temp1 = theTrees[ i ];
			
			// The second is either i on the rhs or NULL
            BinomialNode<T>* temp2 = ( i < rhs.theTrees.size( ) ) ? rhs.theTrees[ i ] : NULL;

			// Select the case we need to evaluate 
			// First, we set which case to 
            int whichCase = temp1 == NULL ? 0 : 1;
            whichCase += temp2 == NULL ? 0 : 2;
            whichCase += carry == NULL ? 0 : 4;

			// Select the case 
            switch( whichCase )
            {
				/* No trees */
				case 0:
				
				/* Only temp1 exists */
				case 1:
					break;
				
				/* Only rhs node exists */
				case 2:
					theTrees[ i ] = temp2;
					rhs.theTrees[ i ] = NULL;
					break;
				
				/* this and rhs, no carry node */
				case 3: 
					// Set Carry to the combined Trees 
					carry = combineTrees( temp1, temp2 );
					
					// Set rhs and theTrees at i to NULL
					theTrees[ i ] = rhs.theTrees[ i ] = NULL;
					break;
				
				/* Only the carry node exists */
				case 4:
					// Set the trees[i] to carry 
					theTrees[ i ] = carry;
					// Free the carry
					carry = NULL;
					break;

				/* Only this and carry, rhs is NULL */
				case 5: /* this and carry */
					carry = combineTrees( temp1, carry );
					theTrees[ i ] = NULL;
					break;
					
				/* Only rhs and carry, this is NULL */					
				case 6:
					carry = combineTrees( temp2, carry );
					rhs.theTrees[ i ] = NULL;
					break;
					
				/* All three */
				case 7:
					theTrees[ i ] = carry;
					carry = combineTrees( temp1, temp2 );
					rhs.theTrees[ i ] = NULL;
					break;
            }
        }

		// Last step, free all the pointers in rhs 
		rhs.theTrees.clear();
		
		// Set the rhs current size to 0
        rhs.currentSize = 0;
		
    }    
	
	void printHeap(){
		
		printHeap( std::cout, printHeap[0] );
		
	}
	

};

#endif