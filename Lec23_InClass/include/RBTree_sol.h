// Implement Deletion
#ifndef RBTREE_H
#define RBTREE2H 

#include "RBTNode.h"
#include <queue>		// Level Order Traversal only
#include <iostream>

template<class T> 
class RBTree { 

	private:

		// Red-Black Tree root node 
		RBTNode<T> *root; 
		
		// Return a pointer to either the location or where the node should be
		RBTNode<T>* search(const T& searchVal) { 
		
			// Set temp to the root node
			RBTNode<T> *temp = root; 
			
			// While temp is NULL
			while (temp != NULL) { 
			
				// If the input value is less than the temp Value
				if (searchVal < temp->value) { 
				
					// Break the loop if we have found the smallest element
					if (temp->left == NULL) 
						break; 
					
					// Otherwise, set the temp to the left child
					else
						temp = temp->left; 
				} 
				
				// If the input value is equal to the value				
				else if (searchVal == temp->value) { 
					break; 
				} 
				else { 
					// Break the loop if we have found the largest element
					if (temp->right == NULL) 
						break; 
					// Otherwise, set the temp to the right child					
					else
						temp = temp->right; 
				} 
			} 
			// Retrn the pointer to the result
			return temp; 
		} 
		
		// Rotate left about node x
		void leftRotate(RBTNode<T>*& x) { 
		
			// new parent will be node's right child 
			RBTNode<T> *nParent = x->right; 
			
			// update root if current node is root 
			if (x == root) 
				root = nParent; 
			
			// Move down nParent
			x->moveDown(nParent); 
			
			// connect x with new parent's left element 
			x->right = nParent->left; 
			
			// connect new parent's left element with node 
			// if it is not null 
			if (nParent->left != NULL) 
				nParent->left->parent = x; 
			
			// connect new parent with x 
			nParent->left = x; 
		} 
		
		// Rotate right about the x node
		void rightRotate(RBTNode<T>*& x) { 
		
			// new parent will be node's left child 
			RBTNode<T> *nParent = x->left; 
			
			// update root if current node is root 
			if (x == root) 
				root = nParent; 
			
			// Move down the new Parent
			x->moveDown(nParent); 
			
			// connect x with new parent's right element 
			x->left = nParent->right; 
			
			// connect new parent's right element with node 
			// if it is not null 
			if (nParent->right != NULL) 
				nParent->right->parent = x; 
			
			// connect new parent with x 
			nParent->right = x; 
		}

		// Swap the colors of two RBTree Nodes
		void swapColors(RBTNode<T>*& x1, RBTNode<T>*& x2) {
			
			COLOR temp; 
			temp = x1->color; 
			x1->color = x2->color; 
			x2->color = temp; 
			
		} 
		
		// Swap Values of two nodes
		void swapValues(RBTNode<T>*& u, RBTNode<T>*& v) { 
		
			T temp; 
			temp = u->value; 
			u->value = v->value; 
			v->value = temp; 
			
		} 
		
		// Fix the scenario where a node and a parent are both red
		void fixRedRed(RBTNode<T>*& x) { 
		
			// if x is root color it black and return 
			if (x == root) { 
				x->color = BLACK; 
				return; 
			} 
			
			// initialize parent, grandparent, uncle 
			RBTNode<T>* parent = x->parent;
			RBTNode<T>* grandparent = parent->parent; 
			RBTNode<T>* uncle = x->uncle(); 
			
			// If the parent's color is BLACK - Cases 2 and 3
			if (parent->color != BLACK) { 
			
				// If the UNCLE not NULL and color is RED
				if (uncle != NULL && uncle->color == RED) {
					
					// Swap the Colors
					parent->color = BLACK; 
					uncle->color = BLACK; 
					grandparent->color = RED; 
					
					// Recursively call fixRedRed on he grandparent
					fixRedRed(grandparent); 
				} 
				
				// Else case means Uncle is a Black Node
				else { 
				
					// Else perform LR, LL, RL, RR 
					if (parent->isOnLeft()) { 
						if (x->isOnLeft()) { 
							// for left right 
							swapColors(parent, grandparent); 
						} 
						else { 
							leftRotate(parent); 
							swapColors(x, grandparent); 
						} 
						// for left left and left right 
						rightRotate(grandparent); 
					} 
					
					// Parent is a right child
					else { 
						if (x->isOnLeft()) { 
							// for right left 
							rightRotate(parent); 
							swapColors(x, grandparent); 
						} 
						else { 
							swapColors(parent, grandparent); 
						} 
				
						// for right right and right left 
						leftRotate(grandparent); 
					} 
				} 
			} 
		} 
		
		// Private method for a copy
		void copyTree( RBTNode<T>*& destin, RBTNode<T>* origin ){
			
			// Return if NULL
			if( origin == NULL ){
				destin = NULL;
				return;
			}
			
			// Use pre-order traversal to copy
			destin = new RBTNode<T>( origin->value );
			destin->color = origin->color;
			
			//destin = temp;
			copyTree( destin->left, origin->left );
			copyTree( destin->right, origin->right );
			
			if( destin->left != NULL ){
				destin->left->parent = destin;
			}
			
			if( destin->right != NULL ){
				destin->right->parent = destin;
			}

		}
		
		// Use Post-Order Traversal to Clean Up tree
		void deleteTree( RBTNode<T>*& currPtr ){
			
			if( currPtr == NULL ){
				return;
			}
			
			// Delete right subtree
			deleteTree( currPtr->right );
			
			// Delete left subtree
			deleteTree( currPtr->left );
			
			// Delete the current pointer
			delete currPtr;
		}

		// Given a node x, find the left most child
		RBTNode<T>* successor(RBTNode<T>*& x) { 
			RBTNode<T> *temp = x; 
			
			while (temp->left != NULL) 
				temp = temp->left; 
			
			return temp; 
		} 
			
		// Find the node that replaces a deleted node in RBT 
		RBTNode<T>* RBTreplace(RBTNode<T>*& x) {
			
			// when node have 2 children 
			if (x->left != NULL and x->right != NULL) 
				return successor(x->right); 
			
			// when leaf 
			if (x->left == NULL and x->right == NULL) 
				return NULL; 
			
			// when single child 
			
			// If left isn't NULL, return left
			if (x->left != NULL) 
				return x->left; 
			
			// Otherwise, return right child
			else
				return x->right; 
		} 
			
	
		// Fix a Double-Black Scenario when deleting
		void fixDoubleBlack(RBTNode<T>*& x) {

			// Return if we've recursively reached the root
			if (x == root) 
				return; 
			
			// Obtain the Node's sibling and parent
			RBTNode<T>* sibling = x->sibling(); 
			RBTNode<T>* parent = x->parent; 
			
			// If the node does not have a sibling, check the parent
			if (sibling == NULL) { 
				fixDoubleBlack(parent); 
			} 
			
			// If we do have a sibling
			else { 
			
				// Case where the sibling is red
				if (sibling->color == RED) { 
				
					// Set the parent's color to Red
					parent->color = RED; 
					
					// Change the sibling's color to Black
					sibling->color = BLACK; 
					
					// If left sibling, rotate right
					if (sibling->isOnLeft()) { 
						rightRotate(parent); 
					} 
					
					// If right sibling, rotate left
					else { 
						leftRotate(parent); 
					} 
					fixDoubleBlack(x); 
				} 
				
				// Case where sibling is black
				else { 
				
					// If the sibling does not have a red child
					if ( !sibling->hasRedChild() ) { 
					
						// 2 black children 
						// Make the sibling's color red
						sibling->color = RED; 
						
						// If the parent's color is black, fix the double black
						if (parent->color == BLACK) 
							fixDoubleBlack(parent); 
						
						// Otherwise, make the parent's color black
						else
							parent->color = BLACK; 
					} 
				
					// The the black sibling has a red child 
					else { 
						
						// In the case where the sibling's left child is red
						if (sibling->left != NULL && sibling->left->color == RED) { 
						
							// If the sibling is a left child
							if (sibling->isOnLeft()) { 
								// left left 
								sibling->left->color = sibling->color; 
								sibling->color = parent->color; 
								rightRotate(parent); 
							} 
							else { 
								// right left 
								sibling->left->color = parent->color; 
								rightRotate(sibling); 
								leftRotate(parent); 
							} 
						}
						
						// This means the red child must be on the right and red
						else { 
							if (sibling->isOnLeft()) { 
								// left right 
								sibling->right->color = parent->color; 
								leftRotate(sibling); 
								rightRotate(parent); 
							} 
							else { 
								// right right 
								sibling->right->color = sibling->color; 
								sibling->color = parent->color; 
								leftRotate(parent); 
							} 
						}	 
						parent->color = BLACK; 
					} 
				} 
			} 
		} 

		// Print the value
		void printValues( const RBTNode<T>* x, std::ostream& output ) const{
			
			// Print values 
			output << "{" << x->value;
			
			// Print Color 
			if( x->color == RED ){
				output << ", Color: RED} ";
			}
			else{
				output << ", Color: BLACK} ";
			}
			
		}

		// Print the In Order Traversal
		void inOrder( const RBTNode<T>* x, std::ostream& output ) const{ 

			if (x == NULL){
				return; 
			}
			
			// Call left 
			inOrder(x->left, output); 
			
			// Print values 
			printValues(x, output);
			
			// Call Right
			inOrder(x->right, output); 
		} 

		// Print the Pre Order Traversal
		void preOrder( const RBTNode<T>* x, std::ostream& output ) const{ 

			if (x == NULL){
				return; 
			}
			
			// Print values 
			printValues(x, output);
			
			// Call left 
			preOrder(x->left, output); 
			
			// Call Right
			preOrder(x->right, output); 
		}

		// Print the post order traversal
		void postOrder( const RBTNode<T>* x, std::ostream& output ) const{ 

			if (x == NULL){
				return; 
			}
			
			// Call Right
			postOrder(x->right, output); 
			
			// Call left 
			postOrder(x->left, output); 
			
			// Print values 
			printValues(x, output);
			
		} 

		// Printing Post Order
		void levelOrder( const RBTNode< T >* treeRoot, std::ostream& output ) const{
			
			// Return if currNode is null 
			if( treeRoot == NULL ){
				return;
			}
			
			// Create a queue of void pointers
			std::queue< void * > levelQueue;

			// Cast the treeRoot to void * and push onto the queue
			levelQueue.push( (void *)treeRoot );
			
			// Just like BFS, iterate until the queue is empty
			while( !levelQueue.empty() ){
				
				// Take the address from the front of the queue and 
				// cast to a RBTNode<T>* and set to a temp value currNode
				RBTNode< T >* currNode = ( RBTNode< T >* )levelQueue.front();
				
				// Remove the element from the front of the queue
				levelQueue.pop();
				
				// Print values 
				printValues(currNode, output);
				
				if( currNode->left != NULL ){
					levelQueue.push( (void *)(currNode->left) );
				}
				
				if( currNode->right != NULL ){
					levelQueue.push( (void *)(currNode->right) );
				}
			}
		}			
		
		void delete_tree( RBTNode< T >* curr_node ){
			
			
			if( curr_node == NULL )
				return;
			
			delete_tree( curr_node->left );
			delete_tree( curr_node->right );
			
			delete curr_node;
			
		}
		
		void print_addresses( std::ostream& output, const RBTNode< T >* curr_node ) const {

			if( curr_node == NULL )
				return;
			
			// Create a queue of void pointers
			std::queue< void * > levelQueue;
			
			// Cast the treeRoot to void * and push onto the queue
			levelQueue.push( (void *)curr_node );
			
			// Just like BFS, iterate until the queue is empty
			while( !levelQueue.empty() ){
				
				// Take the address from the front of the queue and 
				// cast to a RBTNode<T>* and set to a temp value front_node
				RBTNode< T >* front_node = ( RBTNode< T >* )levelQueue.front();
				
				// Remove the element from the front of the queue
				levelQueue.pop();
				
				// Print values 
				output << front_node->value << " " << front_node << " " << front_node->color << " ";
				output << front_node->parent << " " << front_node->left << " " << front_node->right << std::endl;
				
				if( front_node->left != NULL ){
					levelQueue.push( (void *)(front_node->left) );
				}
				
				if( front_node->right != NULL ){
					levelQueue.push( (void *)(front_node->right) );
				}
			}

		}			
		
	public: 
		
		// Default Constructor
		RBTree() : root(NULL) { } 
		
		// Destructor
		~RBTree() {
			
			// delete root;
			delete_tree( root );
			
		} 
		
		// Copy Constructor
		RBTree( const RBTree<T>& copy ) : root( NULL ){
			
			copyTree( root, copy.root );
			
		}
		
		// Assignment Operator
		RBTree<T>& operator=( const RBTree<T>& rhs ){
			
			if( this != &rhs ){
				this->root = new RBTNode<T>( rhs.root->value );
				copyTree( this->root, rhs.root );
			}
			return *this;
		}
		
		// Insert a value
		void insert(const T& insertVal) { 
		
			// Create a new node with the value
			RBTNode<T> *newNode = new RBTNode<T>(insertVal); 
			
			// If the root is null, inset at the root
			if (root == NULL) { 
				newNode->color = BLACK; 
				root = newNode; 
			} 
			
			// Otherwise, find the location where the node should be
			else { 
				
				// Get the location where we need to put the value
				RBTNode<T> *temp = search(insertVal); 
			
				// return if value already exists
				if (temp->value == insertVal) { return; } 
			
				// if value is not found, search returns the node 
				// where the value is to be inserted 
				// connect new node to correct node 
				newNode->parent = temp; 
			
				// If the value to insert is less than the temp's value
				if (insertVal < temp->value) 
					// Make it temp's left child
					temp->left = newNode; 
				
				// Otherwise, make it temp's right child
				else
					temp->right = newNode; 
			
				// Check if the insertion created a  
				fixRedRed(newNode);
			} 
		} 
		
		// Given a specific value, delete from the Red-Black Tree
		void deleteByVal(const T& n) { 
		
			if (root == NULL)  
				return; 
			
			// Get the location of n or where n would be
			RBTNode<T> *u = search(n); 
			
			// In the case value is not in the tree
			if (u == NULL || u->value != n) { 
				std::cout << "No node found to delete with value:" << n << std::endl; 
				return; 
			} 
			
			// Delete the node we retrieved
			deleteNode(u); 
		} 
		
		// Delete a node at a given address 
		void deleteNode( RBTNode<T>*& u ){
			
			// Set the updated value of V as the node to replace u
			RBTNode<T>* v = RBTreplace(u);
			
			// If u and v are both black, set to true
			bool uvBlack = ( (v == NULL) || v->color == BLACK ) && u->color == BLACK;
			
			// Set a temporary node parent as u's parent
			RBTNode<T>* parent = u->parent;
			
			// If v is null
			if( v == NULL ){
				
				// If u is the root, then make the tree empty
				if( u == root ){
					root = NULL;
				}
				else{
					// If both uv and v are black, then fix double-black about u (non-NULL)_
					if( uvBlack ){
						fixDoubleBlack(u);
					}
					
					// Otherwise, if u's sibling isn't null, make it's color RED
					else{
						if( u->sibling() != NULL ){
							u->sibling()->color = RED;
						}
					}
		
					// Then make the original parent's appropriate child NULL
					if( u->isOnLeft() )
						parent->left = NULL;
					else
						parent->right = NULL;
				}
				
				// Delete u, the node to be deleted and return
				u->left = NULL;
				u->right = NULL;
				delete u;
				return;
			}
			
			// If v is not NULL, and one of u's children is NULL
			if( u->left == NULL || u->right == NULL ){
				
				// If u is the root, then swap u and v's values, and delete v
				if( u == root ){
					u->value = v->value;
					u->left = u->right = NULL;
					v->left = NULL;
					v->right = NULL;
					delete v;
				}
				else{
					// Set v to u's location, delete u, and update v's parent
					if( u->isOnLeft() ){
						parent->left = v;
					}
					else{
						parent->right = v;
					}
					u->left = NULL;
					u->right = NULL;
					delete u;
					v->parent = parent;
					
					// If u and v were both black, we will need to fixDouble
					if(uvBlack){
						fixDoubleBlack(v);
					}
					else{
						v->color = BLACK;	// Otherwise, just set v to black
					}
				}
				return;
			}
			
			// If we got here, this means: 
			// 1) v is not NULL
			// 2) both of u's children are NULL 
			// Then we need to swap the values of u and v 
			// Then, we recursively delete v
			swapValues(u, v);
			deleteNode(v);
		}
		
		void print_addresses( std::ostream& output ){
			
			output << "root    : " << this << " " << root << std::endl;
			
			output << "Value Address R/B Parent Left Right" << std::endl;
			
			print_addresses( output, root );
			
		}

		// Friend Method to Print the Tree 
		friend std::ostream& operator<<( std::ostream& output, const RBTree<T>& printTree ){
			
			// Print in-order traversal 
			output << "In-order traversal: ";
			printTree.inOrder( printTree.root, output );
			output << std::endl << std::endl;
			
			// Print pre-order traversal 
			output << "Pre-order traversal: ";
			printTree.preOrder( printTree.root, output );
			output << std::endl << std::endl;
			
			// Print post-order traversal 
			output << "Post-order traversal: ";
			printTree.postOrder( printTree.root,output );
			output << std::endl << std::endl;

			// Print leve;-order traversal 
			output << "Level-order traversal: ";
			printTree.levelOrder( printTree.root, output );
			output << std::endl << std::endl;			
			
			return output;
		}

};

#endif
