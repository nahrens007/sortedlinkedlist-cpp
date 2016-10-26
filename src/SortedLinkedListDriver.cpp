/*
 * SortedLinkedListDriver.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: Nathan
 */

#include <iostream>
#include "SortedLinkedList.h"
using namespace std;

// display program instructions to user
void instructions()
{
	cout << "Enter one of the following:\n" << " 1 to insert in list\n"
			<< " 2 to delete from beginning of list\n"
			<< " 3 to delete from end of list\n"
			<< " 4 to end list processing\n";
} // end function instructions

// function to test a list
template< typename T >
void testList(SortedLinkedList< T > &listObject, const string &typeName)
{
	cout << "Testing a List of " << typeName << " values\n";
	instructions();

	int choice; // store user choice
	T value; // store input value

	do // perform user-selected actions
	{
		cout << "? ";
		cin >> choice;

		switch (choice)
		{
		case 1: // insert at front
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insert(value);
			listObject.print();
			break;
		case 2: // remove from front
			if (listObject.removeFromFront(value))
				cout << value << " removed from list\n";

			listObject.print();
			break;
		case 3: // remove from back
			if (listObject.removeFromBack(value))
				cout << value << " removed from list\n";

			listObject.print();
			break;
		} // end switch
	} while (choice < 4); // do .. while

	cout << "End list test\n\n";
} // end function testList

int main()
{
	cout << "Sorted linked list cablam... " << endl;
	// test List of int values
	SortedLinkedList< int > integerList;
	testList(integerList, "integer");

	// test List of double values
	SortedLinkedList< double > doubleList;
	testList(doubleList, "double");

	return 0;
} // end main
