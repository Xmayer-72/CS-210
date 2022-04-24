#include "AVLSearchTreeADT.h"
#include <algorithm>
#include <iostream>
using namespace std;
//getter for height; returns 0 for a null node
template<class T>
int AVLNode<T>::getHeight() const
{
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
	AVLNode<T> currentNode = new AVLNode<T>();
	int bf = ((currentNode.left->getHeight()) - (currentNode.right->getHeight()));
	return bf;
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
	AVLNode<T>* n = new AVLNode<T>;
	insertHelper(n, x);
}
//return root node
//helper function for insertElement
template<class T>
AVLNode<T>* AVLTree<T>::insertHelper(AVLNode<T>* node, const T& x)
{
	if (getRoot() == NULL) {
		AVLNode<T>::AVLNode(x);
	}
	if (x > node->element) {
		node->right = insertHelper(node->right, x);
	} else if (x < node->element) {
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
}
//outputs the keys, rotated CCW 90 degrees
//using reverse in-order traversal
template<class T>
void AVLTree<T>::showAvlST() const
{
	AVLNode<T>* n = new AVLNode<T>;
	showAvlSTHelper(n, n->getHeight());
}
//recursive helper for showAvlST
//outputs the subtree with root at p
//level is the level of the node at p within the tree
template<class T>
void AVLTree<T>::showAvlSTHelper(AVLNode<T>* p, int level) const
{
	int i = p->getHeight();
	for (i; i > 0; --i) {
		showAvlSTHelper(p->right, i);
		cout << p->element << " ";
	}
	showAvlSTHelper(getRoot(), 0);
	cout << p->element << " ";

	for (i; i > 0; --i) {
		showAvlSTHelper(p->left, i);
		cout << p->element << " ";
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
	AVLNode<T> *t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t->setHeight( max(t->getHeight(), t->getHeight()) + 1);
	t1->setHeight( max(t1->getHeight(), t1->getHeight()) + 1);
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
