/*
CS 210
Craig Hughes, Michael Lazicki, Conrad Mayer
*/

#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int> subArray, int start, int end, int target);
void printVector(vector<int> array);

vector<int> list{};

//Insertion sort
int main() {
	int index, addedValue;
	cout << "Enter a value to be added to the list, enter a non-int to end" << endl;
	while (cin >> addedValue)
	{
		index = binarySearch(list, 0, list.size(), addedValue);
		cout << "the inseted index is: " << index << endl;
		list.insert(list.begin()+index, addedValue);
		printVector(list);
		cout << "Enter a value to be added to the list, enter a non-int to end" << endl;
	}

}

int binarySearch(vector<int> array, int start, int end, int target)
{
	//if the array is empty or the target is smaller than the beginning element, return 0
	if (array.size() == 0 || array.front() >= target) {
		return 0;
	}

	//if the target is larger than the end element, return the back index of the array
	if (array.back() < target) {
		return array.size();
	}

	//find closest index to target and return it
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (target == array[mid])
			return mid + 1;
		else if (target > array[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}

	return start;
}

void printVector(vector<int> array) {
	cout << "vecor contains: ";
	for (int i = 0; i < array.size()-1; i++) {
		cout << array.at(i) << ", ";
	}
	cout << array.at(array.size()-1) << endl;
}