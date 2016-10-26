/*
 * Driver for testing Ninja capabilities.
 *
 * Nathan Ahrens
 * 10/19/2016
 */

#include <iostream>
#include "SortedLinkedList.h"
#include "Ninja.h"
using namespace std;

int main()
{
	cout << "ninjas ultimatum" << endl;
	// test List of int values
	SortedLinkedList<Ninja> ninjas;
	Ninja temp;
	Ninja n1(3, "Arney");
	Ninja n2(2, "Joe");
	Ninja n3(5, "noobs");
	Ninja n4(1, "beg");

	ninjas.insert(n1);
	ninjas.insert(n2);
	ninjas.insert(n3);
	ninjas.insert(n4);

	ninjas.print();



	ninjas.print();

	cout << endl << "removing from list ..." << endl;
	ninjas.removeFromBack(temp);
	cout << temp << endl;
	ninjas.removeFromFront(temp);
	cout << temp << endl;
	ninjas.removeFromBack(temp);
	cout << temp << endl;

	return 0;
} // end main
