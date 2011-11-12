//============================================================================
// Name        : main.cpp
// Author      : Yuriy Myronchenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "OrderedCollection.h"
#include "SortedCollection.h"
using namespace std;

int printInt(int x){
	cout << x << " " << endl;
	return x * 2;
}

int main() {
 	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	OrderedCollection c1 = OrderedCollection();
	cout << "isEmpty: " << c1.isEmpty() << endl;
	cout << "size: " << c1.size() << endl;
	cout << "basicSize: " << c1.basicSize() << endl;
	for (int var = 1; var < 7; ++var) {
		c1.insertAt(var,var);
		c1.print();
	}
	c1.insertAt(7,7);
	c1.print();
	for (int var = 1; var < 10; ++var) {
		c1.insertAt(1,var * 10);
		c1.print();
	}
	c1.insertAt(1,1111);
	c1.print();
	for (int var = 1; var < 9; ++var) {
		c1.insertAt(16,var * 100);
		c1.print();
	}
	c1.insertAt(16,2222);
	c1.print();

	for (int var = 1; var < 10; ++var) {
		c1.insert(var * 9999);
		c1.print();
	}

	cout << "isEmpty: " << c1.isEmpty() << endl;
	cout << "size: " << c1.size() << endl;
	cout << "basicSize: " << c1.basicSize() << endl;

	c1.print();
	int i1, i2, i3, i4 = 0;
	i1 = c1.find(1111);
	cout << i1 << endl;
	c1.removeAt(i1);
	c1.print();

	i2 = c1.find(7);
	cout << i2 << endl;
	c1.removeAt(i2);
	c1.print();

	i3 = c1.find(9999);
	cout << i3 << endl;
	c1.removeAt(i3);
	c1.print();

	i4 = c1.find(998);
	cout << i4 << endl;
	c1.removeAt(i4);
	c1.print();

	c1.removeAt(2);
	c1.print();

	c1.removeAt(c1.size()-1);
	c1.print();

	c1.doFunc(*printInt);
	c1.print();

	OrderedCollection c2(999);
	OrderedCollection c3(c2);
	c2.print();
	c3.print();
	c2.insertAt(2,3).insert(9).removeAt(1).insertAt(1,1111);
	c2.print();
	c3.print();

	c2[1] = 10000;
	int test = c2[1];
	cout << "test is " << test << endl;

	c3 = c2;
	c2 = c2;
	c3.insert(5);
	c3.doFunc(*printInt);
	SortedCollection sc1 = SortedCollection();

	sc1.insert(10).insert(9).insert(8).insert(7).insert(1).insert(2).insert(9);
	sc1.print();

	SortedCollection sc2(c1);
	sc2.print();

	return 0;
}
