//SOLL_ADT.h
//ADT specification/interface for self-organizing linked list ADT

#pragma once

#include <string>

template<class T>
class SOLLNode
{
public:

	SOLLNode() {};
	SOLLNode(const T& theData, SOLLNode<T>* theLink) : data(theData), link(theLink) {};

	T data;
	SOLLNode<T>* link;
};

template <class T>
class SOLLADT
{
public:
	SOLLADT();

	void insert(T);
	SOLLNode<T>* search_helper(T);
	bool search(T);
	bool search_mtf(T);
	bool search_t(T);
	
	void showSOLL();

protected:
	SOLLNode<T>* head;
};
