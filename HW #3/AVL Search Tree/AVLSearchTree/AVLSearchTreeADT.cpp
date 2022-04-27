#include "AVLSearchTreeADT.h"
#include <algorithm>
#include <iostream>
using namespace std;
//getter for height; returns 0 for a null node
template<class T>
int AVLNode<T>::getHeight() const
{
	if (this == NULL)
	{
		return 0;
	}
	return height;
}
template<class T>
void AVLNode<T>::setHeight(int newHeight)
{
	height = newHeight;
}
//calculate the balance factor for this node, based on its children's heights
template<class T>
int AVLNode<T>::calculateBalanceFactor()
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (left)
	{
		leftHeight = left->getHeight();
	}
	if (right)
	{
		rightHeight = right->getHeight();
	}
	balanceFactor = leftHeight - rightHeight;
	return balanceFactor;
}
template<class T>
AVLTree<T>::AVLTree()
{
	root = NULL;
}
//insert the element x into the AVL Tree
template<class T>
void AVLTree<T>::insert(const T& x)
{
	if (getRoot() == nullptr)
	{
		AVLNode<T>* newNode = new AVLNode<T>(x);
		setRoot(newNode);
		getRoot()->balanceFactor = getRoot()->calculateBalanceFactor();
	}
	else
	{
		root = insertHelper(getRoot(), x);
	}
	cout << x << " is Inserted" << endl;
}
//return root node
//helper function for insertElement
template<class T>
AVLNode<T>* AVLTree<T>::insertHelper(AVLNode<T>* node, const T& x)
{
	/*
	if (getRoot() == NULL) {
		AVLNode<T>::AVLNode(x);
	}
	if (x > node->element) {
		node->right = insertHelper(node->right, x);
	}
	else if (x < node->element) {
		node->left = insertHelper(node->left, x);
	}
	else {
		return getRoot();
	}

	node->setHeight(1 + max(node->left->getHeight(), node->right->getHeight()));

	int balance = node->calculateBalanceFactor();

	if (balance > 1 && x < node->left->element) {
		LLRotateWithLeftChild(node);
	}
	if (balance < -1 && x < node->right->element) {
		RRRotateWithRightChild(node);
	}
	if (balance > 1 && x > node->left->element) {
		LRDoubleWithLeftChild(node);
	}
	if (balance < -1 && x > node->right->element) {
		RLDoubleWithRightChild(node);
	}
	return getRoot();
	*/

	    ////////////////////////////////////////////////////////////// SEE HERE!
	    if (node == nullptr)
		{
			return new AVLNode<T>(x);
		}
		else
		{
			if (x < node->element)
			{
				node->left = insertHelper(node->left, x);
			}
			else if (x > node->element)
			{
				node->right = insertHelper(node->right, x);
			}
			//duplicate key; do not insert it
			else
			{
				return node;
			}

			//update node height
			node->setHeight(max(node->left->getHeight(), node->right->getHeight()) + 1);
			node->balanceFactor = node->calculateBalanceFactor();

			if (node->balanceFactor > 1)
			{
				//LL
				if (x < node->left->element)
				{
					LLRotateWithLeftChild(node);
				}
				//LR
				else if (x > node->left->element)
				{
					LRDoubleWithLeftChild(node);
				}
			}
			else if (node->balanceFactor < -1)
			{
				//RR
				if (x > node->right->element)
				{
					RRRotateWithRightChild(node);
				}
				//RL
				else if (x < node->right->element)
				{
					RLDoubleWithRightChild(node);
				}
			}
			return node;
		}
	
	
}

//outputs the keys, rotated CCW 90 degrees
//using reverse in-order traversal
template<class T>
void AVLTree<T>::showAvlST() const
{
	if (getRoot() == 0)
	{
		cout << "Empty tree" << endl;
	}
	else
	{
		cout << endl;
		showAvlSTHelper(getRoot(), 1);
		cout << endl;
	}
}
//recursive helper for showAvlST
//outputs the subtree with root at p
//level is the level of the node at p within the tree
template<class T>
void AVLTree<T>::showAvlSTHelper(AVLNode<T>* p, int level) const
{
	if (p != 0)
	{
		//output right subtree
		showAvlSTHelper(p->right, level + 1);
		for (int j = 0; j < level; j++) cout << "\t"; //set j to int
		//output key
		cout << " " << p->element;
		//two children
		if ((p->left != 0) && (p->right != 0)) cout << "<";
		//only right child
		else if (p->right != 0) cout << "/";
		//only left child
		else if (p->left != 0) cout << "\\";
		cout << endl;
		//output left subtree
		showAvlSTHelper(p->left, level + 1);
	}
}
//outputs the balance factors, rotated CCW 90 degrees
//using reverse in-order traversal
template<class T>
void AVLTree<T>::showBF() const
{
	// Implement here!
}
//recursive helper for showBF
//outputs the balance factors of subtree with root at p
//level is the level of the node at p within the tree
template<class T>
void AVLTree<T>::showBFHelper(AVLNode<T>* p, int level) const
{
	// Implement here!
}
template<class T>
void AVLTree<T>::LLRotateWithLeftChild(AVLNode<T>*& t) const
{
	AVLNode<T>* t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t->setHeight(max(t->getHeight(), t->getHeight()) + 1);
	t1->setHeight(max(t1->getHeight(), t1->getHeight()) + 1);
	t = t1;
}
template<class T>
void AVLTree<T>::RRRotateWithRightChild(AVLNode<T>*& t) const
{
	AVLNode<T>* t1 = t->right;
	t->right = t1->right;
	t1->left = t;
	t->height = max(t->getHeight(), t->getHeight()) + 1;
	t1->height = max(t1->getHeight(), t1->getHeight()) + 1;
	t = t1;
}
template<class T>
void AVLTree<T>::LRDoubleWithLeftChild(AVLNode<T>*& t) const
{
	RRRotateWithRightChild(t->left);

	LLRotateWithLeftChild(t);
}
template<class T>
void AVLTree<T>::RLDoubleWithRightChild(AVLNode<T>*& t) const
{
	LLRotateWithLeftChild(t->right);

	RRRotateWithRightChild(t);
}
template<class T>
AVLNode<T>* AVLTree<T>::getRoot() const //added function to access the root
{
	return root;
}
template<class T>
void AVLTree<T>::setRoot(AVLNode<T>* newRoot)
{
	root = newRoot;
}
