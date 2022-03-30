#include "LeftistMinHeapADT.cpp"
#include <iostream>

using namespace std;

int main()
{
	cout << "Given Test Cases:\n**********" << endl;

	//LH1
	cout << "LH1: Insert 5, 6, 12 and 15\n\n";
	LeftistHeap<int> lhInt1;
	lhInt1.insert(5);
	lhInt1.insert(6);
	lhInt1.insert(12);
	lhInt1.insert(15);
	cout << "LH1:\n" << endl;
	cout << "Print priority values:" << endl;
	lhInt1.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt1.showSPL();
	cout << endl;


	//LH2
	cout << "LH2: Insert 7, 14, 3, 8, and 11\n\n";
	LeftistHeap<int> lhInt2;
	lhInt2.insert(7);
	lhInt2.insert(14);
	lhInt2.insert(3);
	lhInt2.insert(8);
	lhInt2.insert(11);
	cout << "LH2:\n" << endl;
	cout << "Print priority values:" << endl;
	lhInt2.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt2.showSPL();
	cout << endl;

	cout << "Merge LH1 with LH2\n\n";
	//merge
	cout << "Merge(LH1,LH2):\n" << endl;
	lhInt1.merge(lhInt2);
	cout << "Print priority values:" << endl;
	lhInt1.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt1.showSPL();
	cout << endl;


	//LH3
	cout << "LH3: Insert 77, 22, 9, 68, 16, 34, 13 and 8\n\n";
	LeftistHeap<int> lhInt3;
	lhInt3.insert(77);
	lhInt3.insert(22);
	lhInt3.insert(9);
	lhInt3.insert(68);
	lhInt3.insert(16);
	lhInt3.insert(34);
	lhInt3.insert(13);
	lhInt3.insert(8);
	cout << "LH3:\n" << endl;
	cout << "Print priority values:" << endl;
	lhInt3.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt3.showSPL();
	cout << endl;

	cout << "DeleteRoot(LH3)\n\n";
	//deleteMin
	cout << "DeleteMin(LH3):\n" << endl;
	lhInt3.deleteMin();
	cout << "Print priority values:" << endl;
	lhInt3.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt3.showSPL();
	cout << endl;

	cout << "DeleteRoot(LH3)\n\n";
	cout << "DeleteMin(LH3):\n" << endl;
	lhInt3.deleteMin();
	cout << "Print priority values:" << endl;
	lhInt3.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt3.showSPL();
	cout << endl;


	cout << "Our Test Cases:\n**********" << endl;


	// Our Test Cases
	//LH4
	cout << "LH4: Insert 12, 2, 7, 8, 56, 74, 53 and 3\n\n";
	LeftistHeap<int> lhInt4;
	lhInt4.insert(12);
	lhInt4.insert(2);
	lhInt4.insert(7);
	lhInt4.insert(8);
	lhInt4.insert(56);
	lhInt4.insert(74);
	lhInt4.insert(53);
	lhInt4.insert(3);
	cout << "LH3:\n" << endl;
	cout << "Print priority values:" << endl;
	lhInt4.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt4.showSPL();
	cout << endl;

	cout << "DeleteRoot(LH4)\n\n";
	//deleteMin
	cout << "DeleteMin(LH4):\n" << endl;
	lhInt4.deleteMin();
	cout << "Print priority values:" << endl;
	lhInt4.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt4.showSPL();
	cout << endl;

	cout << "DeleteRoot(LH4)\n\n";
	cout << "DeleteMin(LH4):\n" << endl;
	lhInt4.deleteMin();
	cout << "Print priority values:" << endl;
	lhInt4.showLH();
	cout << endl;
	cout << "Print SPL values:" << endl;
	lhInt4.showSPL();
	cout << endl;





	system("pause");
	return 0;
}
