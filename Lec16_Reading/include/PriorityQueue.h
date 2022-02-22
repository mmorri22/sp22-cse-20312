#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BinomialHeap.h"

template<class T>
struct PriorityQueue {

	private:

		BinomialHeap<T> heap;
		unsigned int max_len;
		unsigned int queueSize;

	public:

		// Default constructor
		PriorityQueue() : heap(), max_len(-1), queueSize( 0 ) {}

		// Constructor with limited queue size
		PriorityQueue(unsigned int max) : heap(), max_len(max), queueSize( 0 ) {}
		
		void push(T elem){

			if(queueSize < max_len){

				// Change from push_back to insert
				heap.insert( elem );
				queueSize++;

			}
		}
		
		void pop(){

			if(queueSize > 0){
				heap.deleteMin();
				queueSize--;
			}
		}

		T front() const{
			return heap.findMin();
		}
		
		unsigned int max_size() const{
			return max_len;
		}

		unsigned int size() const{
			return queueSize;
		}

		bool empty() const{
			return queueSize == 0;
		}

};

#endif
