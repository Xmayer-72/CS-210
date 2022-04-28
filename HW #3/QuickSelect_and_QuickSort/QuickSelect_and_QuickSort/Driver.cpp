#include <iostream>
#include "QuickSelect_and_QuickSort.h"
using namespace std;
void QuickSelectTest()
{
	cout << "------------------------\n";
	cout << "QuickSelect Testing:\n";
	cout << "------------------------\n";
	cout << "\n\n";
	cout << "1. Given Test Cases:\n";
	array<int, 15> TestCaseArray = { 2, 3, 5, 8, 12, 1, 7, 10, 13, 30, 6, 14, 15,
	18, 22 };
	cout << "\nInput Array: \n\n";
	printArray(TestCaseArray);
	cout << "\n\n";
	int fourthSmallest = QuickSelect(4, TestCaseArray);
	cout << "\n\n";
	cout << "The 4th Smallest item is: " << fourthSmallest;
	int eigthSmallest = QuickSelect(8, TestCaseArray);
	cout << "\n\n";
	cout << "The 8th Smallest item is: " << eigthSmallest;
	int twelfthSmallest = QuickSelect(12, TestCaseArray);
	cout << "\n\n";
	cout << "The 12th Smallest item is: " << twelfthSmallest;
	cout << "\n\n";
	cout << "\n\n";
	cout << "2. Our Test Cases:\n";

	array<int, 15> TestCaseArray2 = { 4, 1, 5, 8, 12, 6, 7, 10, 13, 30, 44, 14, 15,
	18, 22 };
	cout << "\nInput Array: \n\n";
	printArray(TestCaseArray2);
	cout << "\n\n";
	int fourthSmallest2 = QuickSelect(4, TestCaseArray2);
	cout << "\n\n";
	cout << "The 4th Smallest item is: " << fourthSmallest2;
	int eigthSmallest2 = QuickSelect(8, TestCaseArray2);
	cout << "\n\n";
	cout << "The 8th Smallest item is: " << eigthSmallest2;
	int twelfthSmallest2 = QuickSelect(12, TestCaseArray2);
	cout << "\n\n";
	cout << "The 12th Smallest item is: " << twelfthSmallest2;
	cout << "\n\n";
	cout << "\n\n";

	


}
void QuickSortTest()
{
	cout << "------------------------------------------\n";
	cout << " Quicksort using Median as Pivot Testng:\n";
	cout << "------------------------------------------\n";
	cout << "\n\n";
	array<int, 15> TestCaseArray = { 2, 3, 5, 8, 12, 1, 7, 10, 13, 30, 6, 14, 15,
	18, 22 };
	cout << "1. Given Test Cases:\n";
	cout << "\nInput Array: \n\n";
	printArray(TestCaseArray);
	cout << "\n\n";
	QuickSort(TestCaseArray);
	cout << "\n\nSorted Array: \n\n";
	printArray(TestCaseArray);
	cout << "\n\n";
	cout << "\n\n";
	cout << " 2. Our Test Cases:\n";


	array<int, 15> TestCaseArray2 = { 8, 3, 5, 11, 12, 1, 7, 10, 13, 30, 36, 14, 15,
	28, 22 };
	cout << "\nInput Array: \n\n";
	printArray(TestCaseArray2);
	cout << "\n\n";
	QuickSort(TestCaseArray2);
	cout << "\n\nSorted Array: \n\n";
	printArray(TestCaseArray2);
	cout << "\n\n";
	cout << "\n\n";
	


}
int main()
{
	QuickSelectTest();
	cout << "\n\n\n";
	QuickSortTest();
	cout << "\n\n\n";
	system("pause");
	return 0;
}
