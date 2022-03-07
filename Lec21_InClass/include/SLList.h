/****************************************
 * File name: SLList.h 
 * Author: Matthew Morrison 
 * Contact E-mail: matt.morrison@nd.edu 
 * 
 * This file contains a solution for a Singularly
 * Linked List Class, with an inOrderInsert 
 * function to put in the bottles in alphabetical 
 * order, as directed in the Final Project 
 * portion.
 * *************************************/

#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.h"

template<class T>
class LinkedList{

    public:
    
        Node<T> *head;
        Node<T> *tail;
        
        /************************************
         * Function Name: LinkedList<T>
         * Preconditions: none
         * Postconditions: none 
         * Constructor with a new Node 
         * *********************************/
        LinkedList<T>()
        {
            // new Node() creates a Node will a nullptr
            this->head = new Node<T>();
            this->tail = new Node<T>();
        }

        /************************************
         * Function Name: ~LinkedList<T>
         * Preconditions: none
         * Postconditions: none 
         * Destructor 
         * *********************************/
        ~LinkedList<T>()
        {
            Node<T>* current = head;            // 1
        
            while (current != nullptr)
            { 
                Node<T>* next = current->next;  // 2
                delete current;                 // 3
                current = next;                 //4
            }
        
            head = nullptr;               // Set null at end 
            tail = nullptr;                     // Set null at end 
        }


        /************************************
         * Function Name: operator=
         * Preconditions: const LinkedList<T>&
         * Postconditions: none 
         * Assignment operator  
         * *********************************/		
		LinkedList<T>& operator=(const LinkedList<T>& copy) {
		    Node<T>* temp = copy.head;
			while(temp != nullptr){
			    this->insert(temp->data);   // (1)
			    temp = temp->next;          // (2)
			}
		}

        /************************************
         * Function Name: insert()
         * Preconditions: T 
         * Postconditions: none
         * Inserts the new element at the end of the linked list   
         * *********************************/          
        void insert(T value){
            if (head->next == nullptr)
            {
                tail = head;                    // Case 1: (1)
                head->next = tail;              // Case 1: (2)
                head->data = value;             // Case 1: (3)
            }
            else
            {
                tail->next = new Node<T>();     // Case 2: (1)
                tail = tail->next;              // Case 2: (2)
                tail->data = value;             // Case 2: (3)
                tail->next = nullptr;           // Case 2: (4)
            }   
            length++;                           // Increment the length 
        }

        /************************************
         * Function Name: inOrderInsert()
         * Preconditions: T 
         * Postconditions: Node<T>*, bool*
         * Inserts the new element in Order as determinec by 
         * the templated type of the linked list, and returns a 
         * pointer to that specific node. If it inserts, set true.
         * Otherwise, set false.
         * *********************************/ 
        Node<T>* inOrderInsert(T value, bool* check){
            if (head->next == nullptr){
                head->next = tail;
                tail = head;
                head->data = value;
                length++;
                *check = true;
                return head;                    // Case 1: (4) Return the location of the 
            }
            else if(value < head->data){
                Node<T>* temp = new Node<T>();
                temp->data = value;
                temp->next = head;
                head = temp;
                *check = true;
                length++;
                return head;
            }
            else
            {
                Node<T>* temp = head;           // Set the temp node equal to the head 
                Node<T>* prev = new Node<T>();  // Allows for iteration though w/o Double Linked List 
                
                while(temp != tail && value > temp->data){
                    prev = temp;
                    temp = temp->next;
                }
                
                if(value < temp->data && value > prev->data){
                    Node<T>* insertMid = new Node<T>();
                    insertMid->data = value;
                    prev->next = insertMid;
                    insertMid->next = temp;
                    *check = true;
                    length++;
                    return insertMid;
                }
                
                else if(temp == tail && value != temp->data){
                    Node<T>* insertEnd = new Node<T>();     // Case 2: (1)
                    insertEnd->data = value;
                    temp->next = insertEnd; 
                    insertEnd->next = tail;
                    tail = insertEnd;
                    tail->next = nullptr;           // Case 2: (4)
                    *check = true;
                    length++;
                    return tail;
                }
                else{   // value == temp->value - Do not insert 
                    *check = false;
                    return temp;
                }
            }   
        }
       /************************************
         * Function Name: setNodeTail
         * Preconditions: Node<T>*
         * Postconditions: none
         * Sets a new Node tail  
         * *********************************/          
        void setNodeTail(Node<T>* temp){
            tail = temp;
        }

       /************************************
         * Function Name: removeNode
         * Preconditions: Node<T>*
         * Postconditions: none
         * Removes a node from the Linked List with 
		 * the same pointer and Node<T>* 
         * *********************************/         
        void removeNode(Node<T>* node)
        {
            if(node == nullptr)
                throw std::out_of_range("invalid LinkedList Node");
            
            else if(node->next != nullptr){
                node->next = node->next->next;
                length--;
            }
        }

       /************************************
         * Function Name: deleteNode
         * Preconditions: Node<T>*
         * Postconditions: none
         * Deletes a node with the data T key 
         * *********************************/   
        void deleteNode(Node<T>* key){
            
            if(head == nullptr)
                throw std::out_of_range("invalid LinkedList Node");
            
            else if(head == key){
                
                // First, ensure that a new node is created for a 
                // SLL if the head node is deleted. This permits 
                // another row to be entered after the Pharmacy is 
                // completely empty. Otherwise, you will get a 
                // segmentation fault.
                if(head->next == nullptr){
                    head = new Node<T>();
                    length = 0;
                    return;
                }
                
                // Head, move the head node over by one.
                else{
                    head = head->next;  length--;
                    return;
                }
                
            }
            
            Node<T>* current = head;
            Node<T>* prev = nullptr;
            
            while(current != nullptr && current != key){
                prev = current;
                current = current->next;
            }
            
            if(current == nullptr)
                std::cout << "Element " << key << "is not in the Linked List" << std::endl;
                
            //delete cur node
            prev->next = current->next;
            length--;
        }
 
        size_t getLength(){
            return length;
        }
        
        /************************************
         * Function Name: createCycle()
         * Preconditions: none
         * Postconditions: none
         * Sets the tail of new List equal to the head  
         * *********************************/          
        void createCycle(){
            tail->next = head;
        }

       /************************************
         * Function Name: breakCycle()
         * Preconditions: none
         * Postconditions: none
         * Sets the tail of new List equal to a nullptr
         * must only be called after a createCycle call 
         * *********************************/          
        void breakCycle(){
            tail->next = nullptr;
        }
        
        friend std::ostream& operator<< (std::ostream& stream, const LinkedList<T>* theList){
            Node<T>* temp;

            if (theList->head == NULL)
            {
                return stream;
            }
        
            temp = theList->head;
        
            while (temp != NULL)
            {
                stream << temp->data << " " ;
                temp = temp->next;
            }
            
            return stream;
        }
    
    private:
        size_t length = 0;
    
};

/************************************
 * Function Name: rotateRight()
 * Preconditions: int
 * Postconditions: none
 * creates a cycle, then rotates the head and 
 * tail by the number represented by the integer 
 * then breaks the cycle 
 * *********************************/ 
template<class T>
void rotateLeft(LinkedList<T>* list, int rotations){
    
    // Create the cycle 
    list->createCycle();

    // Move the pointer to the right by one each loop
    while(rotations > 0){
        list->head = list->head->next;
        list->tail = list->tail->next;
        rotations--;
    }
    
    // break the cycle 
    list->breakCycle();
}

#endif