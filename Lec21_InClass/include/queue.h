/****************************************
 * File name: queue.h 
 * Author: Matthew Morrison
 * E-mail: matt.morrison@nd.edu 
 * 
 * This file contains the template class
 * for a queue consisting of two stacks
 * *************************************/

#include <stack>

template <typename T>
class queue {
    
    // Two stacks for the input and output
    std::stack<T> in, out;

    /*********************************************
     * Function Name: popIn_pushOut()
     * Preconditions: none 
     * Postconditions: none 
     * This private function puts all the elements
     * on the output stack.
     * ******************************************/ 
    void popIn_pushOut() {
        if (out.empty()) {
        	while (!in.empty()) {
        	    out.push(in.top());
        	    in.pop();
    	    }
        }
    }

    public:

    /*********************************************
     * Function Name: empty
     * Preconditions: none 
     * Postconditions: none 
     * Returns true if both stacks are empty
     * *******************************************/
    	bool empty()     const { 
    	    return in.empty() && out.empty(); 
    	}
    	
    /*********************************************
     * Function Name: front
     * Preconditions: none 
     * Postconditions: const T& 
     * Returns the address to the front element of the 
     * queue (top element of the out stack)
     * *******************************************/
    	const T& front() {
	    	popIn_pushOut();
    	    return out.top();
    	}
 
     /*********************************************
     * Function Name: back
     * Preconditions: none 
     * Postconditions: const T& 
     * Returns the address to the back element of the 
     * queue (top element of the in stack)
     * *******************************************/   	
    	const T& back()  const { 
    	    return in.top(); 
    	}
 
      /*********************************************
     * Function Name: push 
     * Preconditions: const T& 
     * Postconditions: none 
     * Pushes an element into the queue (top of the 
     * in stack)
     * *******************************************/    	
    	void push(const T& value) {
    	    in.push(value);
    	    popIn_pushOut();
    	}

      /*********************************************
     * Function Name: pop 
     * Preconditions: non
     * Postconditions: none 
     * Pop an element from the queue (top of the 
     * out stack)
     * *******************************************/       	
    	void pop() {
    	    popIn_pushOut();
    	    out.pop();
    	}
    	
      /*********************************************
     * Function Name: peek 
     * Preconditions: non
     * Postconditions: none 
     * Pop an element from the queue (top of the 
     * out stack)
     * *******************************************/       	
    	T& peek() {
    	    popIn_pushOut();
    	    return out.top();
    	}
};
