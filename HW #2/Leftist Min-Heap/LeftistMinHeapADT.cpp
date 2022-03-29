#include "LeftistMinHeapADT.h"
#include <iostream>

using namespace std;

template <class T>
LeftistHeap<T>::LeftistHeap()
{

	// Implement here

}



template <class T>
void LeftistHeap<T>::swapChildren(LeftistNode<T>* t) const
{

	// Implement here

}

//Merge the rhs leftist heap into the leftist heap
//rhs becomes empty
template <class T>
void LeftistHeap<T>::merge(LeftistHeap& rhs)
{

	// Implement here

}

template <class T>
LeftistNode<T>* LeftistHeap<T>::merge1(LeftistNode<T>* h1, LeftistNode<T>* h2) const
{

	// Implement here

}

template <class T>
LeftistNode<T>* LeftistHeap<T>::merge2(LeftistNode<T>* h1, LeftistNode<T>* h2) const
{

	// Implement here

}

template <class T>
void LeftistHeap<T>::insert(const T& x)
{

	// Implement here

}

template <class T>
void LeftistHeap<T>::deleteMin()
{

	// Implement here

}

//prints the elements/priority values in the heap
//output is rotated CCW 90 degrees
//using reverse in-order traversal
template <class T>
void LeftistHeap<T>::showLH() const
{

	// Implement here

}

//recursive helper for showLH
//prints the subtree with root node pointed to by p
//level is the level of that node p in the tree/heap
template <class T>
void LeftistHeap<T>::showLHHelper(LeftistNode<T>* p, int level) const
{

	// Implement here

}

//prints the SPL values in the heap
//output is rotated CCW 90 degrees
//using reverse in-order traversal
template <class T>
void LeftistHeap<T>::showSPL() const
{

	// Implement here

}

//recursive helper for showSPL
//prints the subtree with root node pointed to by p
//level is the level of that node p in the tree/heap
template <class T>
void LeftistHeap<T>::showSPLHelper(LeftistNode<T>* p, int level) const
{

	// Implement here

}
