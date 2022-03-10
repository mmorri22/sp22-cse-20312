#include "../include/AddNode.h"
#include "../include/BinNode.h"
#include "../include/NumNode.h"
#include "../include/Node.h"
#include "../include/MultNode.h"
#include "../include/DivNode.h"
#include "../include/SubNode.h"

#include <iostream>

int main(){

  // EQUATION 1 //

	Node* pNode1 = new NumNode(20.0);
	Node* pNode2 = new NumNode(-10.0);
	Node* pNode3 = new NumNode(0.1);

	std::cout<< "First Equation: (20.0 - (-10.0) * 0.1)"<< std::endl;

	Node* pNode4 = new MultNode(pNode2,pNode3);

	std::cout<<" Multiplying : " << pNode2 -> Calc() << " + (" << pNode3 -> Calc() << ")"<< std::endl;

	Node* pNode5 = new AddNode(pNode1,pNode4);

	std::cout<< "Adding : " << pNode1 -> Calc() << " and " << pNode4->Calc() << std::endl;

	std::cout<<"Result: " << pNode5->Calc()<< std::endl<< std::endl<< std::endl;

	// EQUATION 2 //


	Node* pNode12 = new NumNode(-20.0);
	Node* pNode22 = new NumNode(6);

	Node* pNode32 = new NumNode(3);

	Node* pNode42 = new NumNode(1);

	Node* pNode52 = new NumNode(5);

	std::cout<<"Second Equation: 5 - (1 / (3 * ( -20 + 6) ) )"<< std::endl;

	Node* par1 = new AddNode(pNode12,pNode22);

	std::cout<<"Adding : " << pNode12 -> Calc() << " + (" << pNode22 -> Calc() << ")"<< std::endl;

	Node* par2 = new MultNode(pNode32,par1);

	std::cout<< "Multiplying : " << pNode32 -> Calc() << " * " << par1 -> Calc() << std::endl;

	Node* par3 = new DivNode(pNode42,par2);

	std::cout<< "Dividing : " << pNode42 -> Calc() << " / " << par2 -> Calc() << std::endl;

	Node* result = new SubNode(pNode52,par3);

	std::cout<< "Subtracting : " << pNode52 -> Calc() << " - " << par3 -> Calc() << std::endl;

	std::cout<<"Result: " << result->Calc()<< std::endl;

	return EXIT_SUCCESS;
}
