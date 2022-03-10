/**********************************************
* File: DLList.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the function definitions and 
* structs for a Linked List Data structure 
**********************************************/

#ifndef DLLIST_H
#define DLLIST_H

#include <cstdlib>
#include <iostream>
#include <unordered_map>

template<class T>
class DLList{
	
	protected:
	
		/* NODE contains the data and a pointer to the next node */
		struct node
		{
			T     data;
			node* next;
			node* prev;
			
			/********************************************
			* Function Name  : checkMemory
			* Pre-conditions : none
			* Post-conditions: none
			* 
			* Checks to see if the *this pointer is 
			* pointing to a valid memory location.
			* Terminates program if not to prevent stack overfloe 
			********************************************/
			void checkMemory(){
				
				if (this == NULL)
				{
					std::cerr <<  "Out of Memory" << std::endl;
					exit (-1);
				} 
				
			}
			
			/********************************************
			* Function Name  : node
			* Pre-conditions : none
			* Post-conditions: none
			* 
			* Node Struct Default Constructor 
			********************************************/
			node() : data(), next(NULL), prev(NULL) {
				
				// Check to ensure address properly allocated
				checkMemory();
				
			}
			
			
			/********************************************
			* Function Name  : node
			* Pre-conditions : none
			* Post-conditions: none
			* 
			* Node Struct Overloaded Constructor with data input 
			********************************************/
			node(T dataIn) : data(dataIn), next(NULL), prev(NULL) {
				
				// Check to ensure address properly allocated				
				checkMemory();
				
			}
			

			/********************************************
			* Function Name  : ~node
			* Pre-conditions : none
			* Post-conditions: none
			*  
			* Delete operator required for PQC since it contains a 
			* private member which is a pointer
			********************************************/
			~node(){
				
				delete next;
				
			}
			

			/********************************************
			* Function Name  : node
			* Pre-conditions : const node& copy
			* Post-conditions: none
			*  
			* Rule of 3: Copy Constructor
			* Required for -weffc++ flag
			********************************************/
			node(const node& copy){
				data = copy.data;
				next = copy.next;
				prev = copy.prev;
			}
			
			
			/********************************************
			* Function Name  : operator=
			* Pre-conditions : const node& assign
			* Post-conditions: node&
			*
			* Rule of 3: Assignment Operator
			* Required for -weffc++ flag 
			********************************************/
			node& operator=(const node& assign){
				
				if(this != &assign){
					this->data = assign.data;
					this->next = assign.next;
					this->prev = assign.prev;
				}
				return *this;
			}
			
			
			/********************************************
			* Function Name  : operator=
			* Pre-conditions : const node* assign
			* Post-conditions: node*
			* 
			* Assignment Operator for Pointer
			* Required for pointer assignment in DLList
			********************************************/
			node* operator=(const node* assign){
				
				if(this != (void *)&assign){
					this->data = assign->data;
					this->next = assign->next;
					this->prev = assign->prev;
				}
				return *this;
			}
			
			
			/********************************************
			* Function Name  : operator!=
			* Pre-conditions : const node* rhs
			* Post-conditions: bool
			*  
			* != Operator for Pointer
			* Required for pointer comparison in DLList
			********************************************/
			bool operator!=(const node* rhs){
				
				return this != (void *)&rhs;
				
			}
			
		};
		
		node* head;	// Head pointer for Singly-Linked List
		node* tail; // Tail point for Doubly-Linked List
		
	public:
	
		/********************************************
		* Function Name  : DLList
		* Pre-conditions : none
		* Post-conditions: none
		* 
		* DLList Default Constructor 
		********************************************/
		DLList() : head(NULL), tail(NULL) {}
		
		
		/********************************************
		* Function Name  : ~DLList
		* Pre-conditions : none
		* Post-conditions: none
		* 
		* Singly Linked List Destructor 
		********************************************/
		virtual ~DLList(){
			
			delete head;

		}
		
		
		/********************************************
		* Function Name  : DLList
		* Pre-conditions : const DLList<T>& copy
		* Post-conditions: none
		* 
		* Copy Constructor for Singly Linked List 
		********************************************/
		DLList(const DLList<T>& copy) : head(NULL), tail(NULL) {

			node* curr = copy.head;
			
			while(curr != NULL){
				
				Insert(curr->data);
					
				curr = curr->next;
				
			}

		}
	
		/********************************************
		* Function Name  : operator=
		* Pre-conditions : const DLList<T>& assign
		* Post-conditions: DLList<T>&
		* 
		* Assignment Operator for Singly Linked List 
		********************************************/
		DLList<T>& operator=(const DLList<T>& assign){
				
			if(this != &assign){
				
				node* prev = NULL;
				node* curr = assign.head;
				
				while(curr != NULL){
					
					this->Insert(curr->data);
						
					prev = curr;
					curr = curr->next;
					
				}
			}
			return *this;
			
		}

		/********************************************
		* Function Name  : Insert
		* Pre-conditions : int value
		* Post-conditions: void   
		* 
		* Creates a Node with value, and inserts at 
		* the end of the Singly Linked List
		********************************************/
		virtual void Insert (T value)
		{
		   node* temp = new node(value);

		   if ( IsEmpty() )
		   {
			   head = temp;
			   tail = temp;
		   }
		   else
		   {
			  node* prev =  NULL;
			  node* curr = head;

			  /* traverse the list until the end */
			  while (curr != NULL)
			  {
				 prev = curr;
				 curr = curr->next;
			  }
		  
			  /* insert the node, temp, at the end */
			  prev -> next = temp;
			  
			  /* Allocate the previous node */
			  prev -> next -> prev = prev;
			  
			  /* Allocate tail */
			  tail = prev -> next;
		   }
		}
		
		
		/********************************************
		* Function Name  : push_front
		* Pre-conditions : T value
		* Post-conditions: none
		* 
		* Puts the element at the front
		* For O(1) insert time
		********************************************/
		void push_front(T value){
			
			// Create new node
			node* temp = new node(value);
			
			// Set temp->next = head
			temp -> next = head;
			
			// Set head equal to temp
			head = temp;
			
		}
		
		
		void push_back(T value){
			
			if( IsEmpty() ){
				Insert( value );
			}
			else{
				
				node* temp = new node(value);
				
				temp->prev = tail;
				
				tail->next = temp;
				
				tail = temp;
				
			}
			
			
		}
		
		bool pop_front(){

			if (IsEmpty ())
			{
			  std::cout << "Can't delete from an empty list" << std::endl;
			  return (-1);
			}

			/* The Target IS the Head */
			node* temp = new node();
			
			if( head == tail ){
			   temp = head;
			   head = NULL;
			   tail = NULL;
			   free(temp);
			   return true;
			}
			else{

			  temp = head;
			  head = head -> next;
			  head->prev = NULL;
			  free (temp);
			  return true;

			}
			
		}
		
		T front() const{
			
			return head->data;
			
		}
		
		
		T back() const{
			
			return tail->data;
			
		}


		/********************************************
		* Function Name  : Delete
		* Pre-conditions : int data
		* Post-conditions: int    
		*  
		* Delets the first instance of data. Returns -1 
		* if not found
		********************************************/
		bool Delete (T target)
		{
		   node* temp = new node(); node* prev = new node(); node* curr = new node();

		   if (IsEmpty ())
		   {
			  std::cout << "Can't delete from an empty list" << std::endl;
			  return (-1);
		   }

		   /* if the target value is the first in the list, move head */
		   else if (target == head -> data)
		   {
			   
			   if( head == tail ){
				   temp = head;
				   head = NULL;
				   tail = NULL;
				   free(temp);
				   return true;
			   }
			   else{
			   
				  temp = head;
				  head = head -> next;
				  head->prev = NULL;
				  free (temp);
				  return true;
			  
			   }
		   }
		   
		   /* traverse the list until the target value is found */
		   else
		   {
			  prev = head;
			  curr = head -> next;

			  while (curr != NULL && curr -> data != target)
			  {
				 prev = curr;
				 curr = curr -> next;
			  }
			  
			  if(curr != NULL)
			  {
				/* delete the node the contains the target value */
				temp = curr;
				
				if(curr == tail){
					tail = prev;
				}
				
				prev -> next = curr -> next;
				free(temp);
				
				if(prev->next != NULL){
					
					prev->next->prev = prev;
				}
				
				return true;
			  }
			  else
			  {
				std::cout << target << " was not in the list" << std::endl;
				return false;
			  }
		   }      
		}


		/********************************************
		* Function Name  : IsEmpty
		* Pre-conditions : node* head
		* Post-conditions: int    
		* 
		* Bool returns if the list contains values
		********************************************/
		bool IsEmpty () const{
			
			return head == NULL && tail == NULL;
		   
		}
		
		
		/********************************************
		* Function Name  : contains
		* Pre-conditions : const T& searchVal
		* Post-conditions: bool
		* 
		* Returns whether the list contains the element 
		********************************************/
		bool contains(const T& searchVal) const{

		   if (IsEmpty()) {
			   
			  return false;
			  
			}
			else{
				
				node* prev =  NULL;
				node* curr = head;
				
				while (curr != NULL && curr -> data != searchVal){
					prev = curr;
					curr = curr -> next;
				}

				return curr != NULL;
			}
		}


		/********************************************
		* Function Name  : operator<<
		* Pre-conditions : std::ostream& output, const DLList<T>& theList 
		* Post-conditions: std::ostream&
		* 
		* Overloaded friend ostream operator for DLList 
		********************************************/
		friend std::ostream& operator<<( std::ostream& output, const DLList<T>& theList ){
			
		   node* curr;

		   if (theList.IsEmpty())
		   {
			  output << "The list is empty" << std::endl;;
		   }
		   else
		   {
			  /* set the current pointer to the first
			  ** node of the list */
			  curr = theList.head;

			  /* Until the end of the list */
			  while (curr != NULL)
			  {
				  /* print the current data item */
				  output << curr->data << " ";

				  /* move to the next node */
				  curr = curr -> next;
			  }
		   } 

		   return output;
		}
		
		
		void deleteDuplicates(){
			
			node* curr;
			std::unordered_map<T, bool> theHash;

			if ( IsEmpty() )
			{
				std::cout << "The list is empty" << std::endl;;
			}
			else{
				
				/* set the current pointer to the first
				** node of the list */
				curr = head;
				
				/* Until the end of the list */
				while (curr != NULL){
					
					if(theHash.count( curr->data ) == 0){
						
						theHash.insert( {curr->data, true} );
						
					}
					else{
						
						// Will delete the first instance
						Delete( curr->data );
					}
					
					// Iterate to the next node
					curr = curr->next;
				}
			}
		}

};

#endif
