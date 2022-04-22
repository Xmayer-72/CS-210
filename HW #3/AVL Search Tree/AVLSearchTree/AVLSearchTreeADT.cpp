#include "AVLSearchTreeADT.h"
#include <algorithm>
#include <iostream>
using namespace std;
//getter for height; returns 0 for a null node
template<class T>
int AVLNode<T>::getHeight() const
{
	// Implement here!
}
template<class T>
void AVLNode<T>::setHeight(int newHeight)
{
	// Implement here!
}
//calculate the balance factor for this node, based on its children's heights
template<class T>
int AVLNode<T>::calculateBalanceFactor()
{
	// Implement here!
}
template<class T>
AVLTree<T>::AVLTree()
{
	// Implement here!
}
//insert the element x into the AVL Tree
template<class T>
void AVLTree<T>::insert(const T& x)
{
	// Implement here!
}
//return root node
//helper function for insertElement
template<class T>
AVLNode<T>* AVLTree<T>::insertHelper(AVLNode<T>* node, const T& x)
{
	// Implement here!
}
//outputs the keys, rotated CCW 90 degrees
//using reverse in-order traversal
template<class T>
void AVLTree<T>::showAvlST() const
{
	// Implement here!
}
//recursive helper for showAvlST
//outputs the subtree with root at p
//level is the level of the node at p within the tree
template<class T>
void AVLTree<T>::showAvlSTHelper(AVLNode<T>* p, int level) const
{
	// Implement here!
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
	AVLNode<T> *t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
	t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;
	t = t1;
}
template<class T>
void AVLTree<T>::RRRotateWithRightChild(AVLNode<T>*& t) const
{
	AVLNode<T>* t1 = t->right;
	t->right = t1->right;
	t1->left = t;
	t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
	t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;
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
	// Implement here!
}
template<class T>
void AVLTree<T>::setRoot(AVLNode<T>* newRoot)
{
	// Implement here!
}
