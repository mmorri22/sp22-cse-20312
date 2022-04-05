#include <iostream>
#include <set>
#include <string>

template<class T>
void printInOrder(std::multiset< T > printTree){
	
	for(const T& curr : printTree){
		
		std::cout << curr << " ";
	}
	std::cout << std::endl;
	
}

int main(){
	
	std::multiset< int > intTree;
	
	intTree.insert(40); intTree.insert(30); 
	printInOrder(intTree);
    intTree.insert(60); intTree.insert(20);
	printInOrder(intTree);
	intTree.erase(40);
	printInOrder(intTree);
	// only one 50 will be added to the multiset 
    intTree.insert(40); intTree.insert(50); intTree.insert(50); 
    intTree.insert(10); 

	printInOrder(intTree);
	
	intTree.erase(30);
	printInOrder(intTree);	
	
	intTree.erase(50);
	printInOrder(intTree);
	
	intTree.erase(20);
	printInOrder(intTree);	
	
    intTree.insert(35); 
	printInOrder(intTree);	
	
	std::multiset< std::string > strTree;
	strTree.insert("A");	strTree.insert("Q");
	strTree.insert("B");	strTree.insert("R");
	strTree.insert("M");	strTree.insert("A");
	printInOrder(strTree);
	strTree.erase("A");
	printInOrder(strTree);
	
	return 0;
}

