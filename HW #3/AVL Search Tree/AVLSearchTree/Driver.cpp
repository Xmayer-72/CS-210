#include "AVLSearchTreeADT.cpp"
#include <iostream>
using namespace std;
int main()
{
	cout << "1. Given Test Cases:" << endl << endl;
	cout << "-----------------------------" << endl << endl;
	cout << "AVL1:" << endl;
	AVLTree<int> tree1;
	cout << "\n\nInsert 4, 10, 3, 6, 5 and 25 into an empty AVL tree\n\n\n\n";
	tree1.insert(4);
	tree1.insert(10);
	tree1.insert(3);
	tree1.insert(6);
	tree1.insert(5);
	tree1.insert(25);
	cout << "Printing keys:" << endl;
	tree1.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree1.showBF();
	cout << endl;
	cout << "AVL2:" << endl;
	AVLTree<int> tree2;
	cout << "\n\nInsert 10, 20, 30, 40, 50, 60 & 70 into an empty AVL tree\n\n\n\
n";
	tree2.insert(10);
	tree2.insert(20);
	tree2.insert(30);
	tree2.insert(40);
	tree2.insert(50);
	tree2.insert(60);
	tree2.insert(70);
	cout << "Printing keys:" << endl;
	tree2.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree2.showBF();
	cout << endl;
	cout << endl;
	cout << "2. Our Test Cases:" << endl << endl;
	cout << "-----------------------------" << endl << endl;
	
	AVLTree<int> tree3;
	cout << "\n\nInsert 10, 40, 20, 80, 60, 50 & 70 into an empty AVL tree\n\n\n\
n";
	tree3.insert(10);
	tree3.insert(40);
	tree3.insert(20);
	tree3.insert(80);
	tree3.insert(60);
	tree3.insert(50);
	tree3.insert(70);
	cout << "Printing keys:" << endl;
	tree3.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree3.showBF();
	cout << endl;
	cout << endl;
	
	system("pause");
	return 0;
}
