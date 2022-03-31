#include "LeftistMinHeapADT.h"
#include <iostream>

using namespace std;

template <class T>
LeftistHeap<T>::LeftistHeap()
{

	root = NULL;

}



template <class T>
void LeftistHeap<T>::swapChildren(LeftistNode<T>* t) const
{

	LeftistNode<T> *temp;
	temp = t->right;
	t->right = t->left;
	t->left = temp;

}

//Merge the rhs leftist heap into the leftist heap
//rhs becomes empty
template <class T>
void LeftistHeap<T>::merge(LeftistHeap& rhs)
{

	root = merge1(root, rhs.root);
	rhs.root = NULL;

}

template <class T>
LeftistNode<T>* LeftistHeap<T>::merge1(LeftistNode<T>* h1, LeftistNode<T>* h2) const
{

	if (h1 == NULL)  return h2;
	if (h2 == NULL)  return h1;

	if (h1->priority < h2->priority) return merge2(h1, h2);
	else return merge2(h2, h1);

}

template <class T>
LeftistNode<T>* LeftistHeap<T>::merge2(LeftistNode<T>* h1, LeftistNode<T>* h2) const
{

	// Recursively merge its right subtree and the other tree h2. 
	h1->right = merge1(h1->right, h2);
	// Swap if needed.
	if (!h1->left) {
		h1->left = h2;
		h2 = NULL;
	} else if (h1->left->spl < h1->right->spl) {
		swapChildren(h1);
	}
	// Update the spl of the merged root.
	h1->spl = h1->right->spl + 1;
	return h1;

}

template <class T>
void LeftistHeap<T>::insert(const T& x)
{

	root = merge1(new LeftistNode<T>(x), root);

}

template <class T>
void LeftistHeap<T>::deleteMin()
{

	//find min 
	LeftistNode<T> *oldRoot = root;
	//merge children
	root = merge1(root->left, root->right);
	//delete min
	delete oldRoot;
}

//prints the elements/priority values in the heap
//output is rotated CCW 90 degrees
//using reverse in-order traversal
template <class T>
void LeftistHeap<T>::showLH() const
{

	if (root == 0) {
		cout << "Empty Heap" << endl;
	}
	else {
		cout << endl;
		showSPLHelper(root, 1);
		cout << endl;
	}

}

//recursive helper for showLH
//prints the subtree with root node pointed to by p
//level is the level of that node p in the tree/heap
template <class T>
void LeftistHeap<T>::showLHHelper(LeftistNode<T>* p, int level) const
{

	int j;
	if (p != 0)
	{
		showSPLHelper(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++) cout << "\t";
		cout << " " << p->Key;   // Output key
		if ((p->left != 0) && (p->right != 0)) cout << "<";
		else if (p->right != 0) cout << "/";
		else if (p->left != 0) cout << "\\";
		cout << endl;
		showSPLHelper(p->left, level + 1); // Output left subtree
	}

}

//prints the SPL values in the heap
//output is rotated CCW 90 degrees
//using reverse in-order traversal
template <class T>
void LeftistHeap<T>::showSPL() const
{

	if (root == 0) {
		cout << "Empty Heap" << endl;
	}
	else {
		cout << endl;
		showSPLHelper(root, 1);
		cout << endl;
	}

}

//recursive helper for showSPL
//prints the subtree with root node pointed to by p
//level is the level of that node p in the tree/heap
template <class T>
void LeftistHeap<T>::showSPLHelper(LeftistNode<T>* p, int level) const
{

	int j;
	if (p != 0)
	{
		showSPLHelper(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++) cout << "\t";
		cout << " " << p->priority;   // Output key
		if ((p->left != 0) && (p->right != 0)) cout << "<";
		else if (p->right != 0) cout << "/";
		else if (p->left != 0) cout << "\\";
		cout << endl;
		showSPLHelper(p->left, level + 1); // Output left subtree
	}

}
