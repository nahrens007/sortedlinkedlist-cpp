/*
 * ListNode.h
 *
 *  Created on: Oct 13, 2016
 *      Author: Nathan
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

/*
 * Forward declaration of class List required to announce that class List
 * exists so it can be used in the friend declaration
 */
template< typename NODETYPE > class SortedLinkedList;

template< typename NODETYPE >
class ListNode
{
	friend class SortedLinkedList< NODETYPE > ; // make List a friend

public:
	ListNode(const NODETYPE &);
	NODETYPE getData() const; // return data in node
private:
	NODETYPE data; // data
	ListNode< NODETYPE > *nextPtr; // next node in list
};
template< typename NODETYPE >
ListNode< NODETYPE >::ListNode(const NODETYPE &info) :
		data(info), nextPtr(0)
{
	// empty body
}

//return copy of data in node
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const
{
	return data;
}
#endif /* LISTNODE_H_ */
