/*
 * LinkedList.h
 *
 *  Created on: Oct 13, 2016
 *      Author: Nathan
 */

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

#include <iostream>
#include "ListNode.h"
using namespace std;

template<typename NODETYPE>
class SortedLinkedList
{
public:
	SortedLinkedList();
	~SortedLinkedList(); // destructor
	void insert(const NODETYPE &); // for sorted insert
	bool removeFromFront(NODETYPE &);
	bool removeFromBack(NODETYPE &);
	bool isEmpty() const;
	void print() const;
private:
	ListNode<NODETYPE> *firstPtr; // pointer to first node
	ListNode<NODETYPE> *lastPtr; // pointer to last node

	// utility function to allocate new node
	ListNode<NODETYPE> *getNewNode(const NODETYPE &);
};
// default constructor
template<typename NODETYPE>
SortedLinkedList<NODETYPE>::SortedLinkedList() :
		firstPtr(0), lastPtr(0)
{
	//empty body
}

// destructor
template<typename NODETYPE>
SortedLinkedList<NODETYPE>::~SortedLinkedList()
{
	if (!isEmpty())
	{
		cout << "Destroying nodes ...\n";

		ListNode<NODETYPE> *currentPtr = firstPtr;
		ListNode<NODETYPE> *tempPtr;

		while (currentPtr != 0) // delete remaining nodes
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		} // end while
	} // end if
	cout << "All nodes destroyed\n\n";
} // end List destructor

// insert at sorted position
template<typename NODETYPE>
void SortedLinkedList<NODETYPE>::insert(const NODETYPE &value)
{
	ListNode<NODETYPE> *newPtr = getNewNode(value); // new node

	if (this->isEmpty())
	{
		this->firstPtr = this->lastPtr = newPtr; // new list has only one node
		return; // nothing else to do; return.
	}

	// Place the node in order
	ListNode<NODETYPE> *currentPtr = this->firstPtr;
	ListNode<NODETYPE> *trailingPtr = currentPtr;

	while (currentPtr != 0)
	{
		if (newPtr->data <= currentPtr->data)
		{
			if (currentPtr == this->firstPtr)
			{
				// If we are in the front of the list...
				newPtr->nextPtr = firstPtr; // point new node to previous 1st node
				this->firstPtr = newPtr; // firstPtr point to the new node
				return;
			}

			// New data is less or equal to current; insert now.
			trailingPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
			return;
		}

		// Update pointers
		trailingPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}

	// Got this far, must insert at end of list.
	this->lastPtr->nextPtr = newPtr;
	this->lastPtr = newPtr;
	return;

}

// delete node from front of the list
template<typename NODETYPE>
bool SortedLinkedList<NODETYPE>::removeFromFront(NODETYPE &value)
{
	if (isEmpty())
		return false;
	else
	{
		ListNode<NODETYPE> *tempPtr = firstPtr; // hold tempPtr to delete

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0; // no nodes remain after removal
		else
			firstPtr = firstPtr->nextPtr; // point to previous 2nd node

		value = tempPtr->data; // return data being removed
		delete tempPtr; // reclaim previous front node
		return true; // delete successful
	} // end else
}

// delete node from back of the list
template<typename NODETYPE>
bool SortedLinkedList<NODETYPE>::removeFromBack(NODETYPE &value)
{
	if (isEmpty())
		return false; // delete unsuccessful
	else
	{
		ListNode<NODETYPE> *tempPtr = lastPtr; // hold tempPtr to delete

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0; // no nodes remain after removal
		else
		{
			ListNode<NODETYPE> *currentPtr = firstPtr;

			//locate second-to-last element
			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr; // move to the next node

			lastPtr = currentPtr; // remove last node
			currentPtr->nextPtr = 0; // this is now the last node
		} // end else

		value = tempPtr->data; // return value from old last node
		delete tempPtr; // reclaim former last node
		return true; // delete successful
	} // end else
} // end function removeFromBack

// is list empty?
template<typename NODETYPE>
bool SortedLinkedList<NODETYPE>::isEmpty() const
{
	return firstPtr == 0;
} // end function isEmpty

// return pointer to newly allocated node
template<typename NODETYPE>
ListNode<NODETYPE> *SortedLinkedList<NODETYPE>::getNewNode(
		const NODETYPE &value)
{
	return new ListNode<NODETYPE>(value);
} // end function getNewNode

// display contents of List
template<typename NODETYPE>
void SortedLinkedList<NODETYPE>::print() const
{
	if (isEmpty()) // List is empty
	{
		cout << "The list is empty\n\n";
		return;
	} // end if

	ListNode<NODETYPE> *currentPtr = firstPtr;

	cout << "The list is:" << endl;

	while (currentPtr != 0)
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	} // end while

	cout << "\n\n";
} // end function print

#endif /* SORTEDLINKEDLIST_H_ */
