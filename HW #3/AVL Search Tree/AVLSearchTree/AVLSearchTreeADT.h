#pragma once 
template<class T>
class AVLTree;
template<class T>
class AVLNode
{
public:
	T element;
	AVLNode* left;
	AVLNode* right;
	int balanceFactor;
	AVLNode(const T theElement, int h = 1) :
		element(theElement), height(h) {}
	int getHeight() const;
	void setHeight(int newHeight);
	int calculateBalanceFactor();
	friend class AVLTree<T>;
private:
	int height;
};
template <class T>
class AVLTree
{
public:
	AVLTree();
	void insert(const T& x);
	void showAvlST() const;
	void showBF() const;
	AVLNode<T>* getRoot() const;
	void setRoot(AVLNode<T>* newRoot);
private:
	AVLNode<T>* root;
	AVLNode<T>* insertHelper(AVLNode<T>* root, const T& x);
	void LLRotateWithLeftChild(AVLNode<T>*& t) const;
	void RRRotateWithRightChild(AVLNode<T>*& t) const;
	void LRDoubleWithLeftChild(AVLNode<T>*& t) const;
	void RLDoubleWithRightChild(AVLNode<T>*& t) const;
	void showAvlSTHelper(AVLNode<T>* p, int level) const;
	void showBFHelper(AVLNode<T>* p, int level) const;
};