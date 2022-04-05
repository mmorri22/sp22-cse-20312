#include "../inc/RBTree.h"
#include <string>

/********************************************
* Function Name  : insertAndPrint
* Pre-conditions : RBTree<T>* tree, T value
* Post-conditions: none
*  
*  Inserts into the Red-Black Tree and prints the
*  in-order and level order traversal to the user
********************************************/
template<class T>
void insertAndPrint(RBTree<T>& tree, T value){

	std::cout << "Inserting: " << value << std::endl;
	tree.insert(value);
	std::cout << tree << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* Main driver file for the program  
********************************************/
int main() { 

  RBTree<int> tree; 
  
  // Showing the results of insertion and deletion
  // Insert: 20, 10, 30, 15, 17, 12, 35, 25, 13, and 9. 
	std::cout << "Red-Black Tree: Integer Template Insertion and Deletion" << std::endl;
	insertAndPrint(tree, 20);
	insertAndPrint(tree, 10);
	insertAndPrint(tree, 30);
	insertAndPrint(tree, 15);
	insertAndPrint(tree, 17);
	insertAndPrint(tree, 12);
	insertAndPrint(tree, 35);
	insertAndPrint(tree, 25);
	insertAndPrint(tree, 13);
	insertAndPrint(tree, 9);
	
	std::cout << "---------------------------------------------------------" << std::endl;
  
  // Now, string test
  std::cout << "Red-Black Tree: std::string Template Insertion and Deletion" << std::endl;
  RBTree<std::string> str_tree;
  insertAndPrint(str_tree, std::string("And"));
  insertAndPrint(str_tree, std::string("our"));
  insertAndPrint(str_tree, std::string("hearts"));
  insertAndPrint(str_tree, std::string("forever,"));
  insertAndPrint(str_tree, std::string("Love"));
  insertAndPrint(str_tree, std::string("thee"));
  insertAndPrint(str_tree, std::string("Notre"));
  insertAndPrint(str_tree, std::string("Dame"));

  return 0; 
} 
