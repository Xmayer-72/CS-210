#pragma once
#include <array>
#include <iostream>
using namespace std;
//Partion function used by selection
template <class T, int N>
void partition(int min, int max, int& pivotpoint, array<T, N>& arr)
{
	// Implement here
}

//-------------------------------------
//   QuickSelect
//-------------------------------------

template <class T, int N>
T Qselection(int min, int max, int k, array<T, N>& arr)
{
	// Implement here
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
	// Implement here
}
