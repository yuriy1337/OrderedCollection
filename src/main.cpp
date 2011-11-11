//============================================================================
// Name        : main.cpp
// Author      : Yuriy Myronchenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "OrderedCollection.h"
using namespace std;

int printInt(int x){
	cout << x << " " << endl;
	return x;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	OrderedCollection c1 = OrderedCollection();
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
	/*OrderedCollection c2(999);
	OrderedCollection c3(c2);
	c2.insertAt(2,3);
	c2.insertAt(3,4);
	c2.insertAt(4,5);
	c2.insertAt(5,6);
	c2.insertAt(6,7);
	c2.insertAt(7,8);
	c2.insertAt(8,9);
	c2.insertAt(9,10);

	c3.doFunc(*printInt);*/
	return 0;
}
