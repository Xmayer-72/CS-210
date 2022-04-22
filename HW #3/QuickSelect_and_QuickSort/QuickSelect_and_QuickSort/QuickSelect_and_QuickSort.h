#pragma once
#include <array>
#include <iostream>
using namespace std;

//Partion function used by selection
template <class T, int N>
void partition(int min, int max, int& pivotpoint, array<T, N>& arr)
{
	int i = 0;
	int j = 0;
	int pivotItem = 0;

	pivotItem = arr[min];
	j = min;
	for (i = min + 1; i <= max; i++) {
		if (arr[i] < pivotItem) {
			j++;
			/*array<T, N> ary1[] = arr[i];
			arr[i] = arr[j];
			arr[j] = ary1[];*/
			std::swap(arr[i], arr[j]);
		}
		pivotpoint = j;
		/*array<T, N> ary2[] = arr[min];
		arr[min] = ary[pivotpoint];
		arr[pivotpoint] = ary2[];*/
		std::swap(arr[min], arr[pivotpoint]);
	}
}

//-------------------------------------
//   QuickSelect
//-------------------------------------

template <class T, int N>
T Qselection(int min, int max, int k, array<T, N>& arr)
{
	int pivot = 0;
	if (min == max) {
		return arr[min];
	}
	else {
		partition(min, max, pivot, arr);
		if (k == pivot) {
			return arr[pivot];
		}
		else if (k < pivot) {
			return Qselection(min, pivot - 1, k, arr);
		}
		else {
			return Qselection(pivot + 1, max, k, arr);
		}
	}
}

//k represents the kth smallest value, 

template <class T, int N>
T QuickSelect(int k, array<T, N>& arr)
{
	return Qselection(0, N - 1, k - 1, arr);
}

//-------------------------------------
//   QuickSort using Median as Pivot
//-------------------------------------

template <class T, int N>
void QuickSortMAP(int min, int max, array<T, N>& arr)
{
	// Implement here
}

template <class T, int N>
void QuickSort(array<T, N>& arr)
{
	QuickSortMAP(0, N - 1, arr);
}

//small helper function to print out arrays
template <class T, int N>
void printArray(array<T, N> arr)
{

}
