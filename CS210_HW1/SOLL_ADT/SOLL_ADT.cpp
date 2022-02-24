//SOLLADT.cpp
//ADT Implementation for self-organizing linked list ADT
#include "SOLL_ADT.h"
#include <string>
#include <iostream>
using namespace std;
template<class T>
SOLLADT<T>::SOLLADT() : head(NULL)
{
};

template<class T>
void SOLLADT<T>::insert(T element)
{

	//SOLLNode<T>* temp = (SOLLNode<T>*)malloc(sizeof(SOLLNode<T>));
	//SOLLNode<T>* head = NULL, * rear = NULL, * current = head;

	/* 1. create and allocate node */
	SOLLNode<T>* newNode = new SOLLNode<T>;

	SOLLNode<T>* rear = head; /* used in step 5*/

	/* 2. assign data to the node */
	newNode->data = element;

	/* 3. set next pointer of new node to null as its the last node*/
	newNode->link = NULL;

	/* 4. if list is empty, new node becomes first node */
	if (head->data == NULL)
	{
		head->data = newNode;
		return;
	}

	/* 5. Else traverse till the last node */
	while (rear->link != NULL) {
		rear = rear->link;
	}
	/* 6. Change the next of last node */
	rear->link = newNode;
	return;



	/*temp->data = element;
	temp->link = NULL;

	while (head != NULL) {

		if (head->data == temp->data) {
			cout << "Item already in List";
		}
		head->link = current->link;
		current->link = rear->link;
	}

	if (head->data == NULL) {
		current->data = temp->data;
		head->link = current->link;
	}
	*/

	// assigning value to the created node;
	/*temp->data = element;
	temp->link = NULL;
	
	// first element of list
	if (head == NULL)
		head = rear = temp;
		
	// rest elements of list
	else {
		rear->link = temp;
		rear = temp;
	}
	*/


};
template<class T>
void SOLLADT<T>::showSOLL()
{

	/*
	while (current->link != NULL) {

		cout << current->data << "->";

	}
	*/
	//traverse the list to display each node
	SOLLNode<T>* current = head;
	while (current->data != NULL)
	{
		cout << current->data << "-->";
		current = current->link;
	}


};
template<class T>
SOLLNode<T>* SOLLADT<T>::search_helper(T element)
{


	// Implement here!


};
template<class T>
bool SOLLADT<T>::search(T element)
{
	
	SOLLNode<T>* current = head;
	SOLLNode<T>* prev = NULL;

	while (current != NULL) {

		if (current->data == element) {

			if (prev != NULL) {

				prev->link = current->link;
				current->link = head;
				head = current;
			}
			
			return true;

		}

	}
	return false;

};
template<class T>
bool SOLLADT<T>::search_mtf(T element)
{

	SOLLNode<T>* current = head;
	SOLLNode<T>* prev = NULL;

	while (current != NULL) {

		if (current->data == element) {

			if (prev != NULL) {

				prev->link = current->link;
				current->link = head;
				head = current;
			}
			return true;
		}
		prev = current;
		current = current->link;
	}
	return false;
	


};
template<class T>
bool SOLLADT<T>::search_t(T element)
{

	SOLLNode<T>* current = head;
	SOLLNode<T>* prev = NULL;
	SOLLNode<T>* prev_prev = NULL;

	while (current != NULL) {

		if (current->data == element) {

			if (prev_prev != NULL) {

				prev_prev->link = current;
				prev->link = current->link;
				current->link = prev;
			}

			else if (prev != NULL) {

				prev->link = current->link;
				current->link = prev;
				head = current;
			}
			return true;
		}
		prev_prev = prev;
		prev = current;
		current = current->link;

	}
	return false;
};