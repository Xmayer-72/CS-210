#pragma once


template <class T>
class LeftistHeap;

template <class T>
class LeftistNode
{
	T priority;
	LeftistNode* left;
	LeftistNode* right;
	int spl;

	LeftistNode(const T& thePriority, LeftistNode* lt = nullptr, LeftistNode* rt = nullptr, int theSpl = 1) :
		priority(thePriority), left(lt), right(rt), spl(theSpl)
	{
	}

	friend class LeftistHeap<T>;
};

template <class T>
class LeftistHeap
{
public:
	LeftistHeap();

	void insert(const T& x);
	void deleteMin();
	void merge(LeftistHeap& rhs);
	void showLH() const;
	void showSPL() const;

private:
	LeftistNode<T>* root;
	LeftistNode<T>* merge1(LeftistNode<T>* h1, LeftistNode<T>* h2) const;
	LeftistNode<T>* merge2(LeftistNode<T>* h1, LeftistNode<T>* h2) const;
	void swapChildren(LeftistNode<T>* t) const;
	void showLHHelper(LeftistNode<T>* p, int level) const;
	void showSPLHelper(LeftistNode<T>* p, int level) const;
};
