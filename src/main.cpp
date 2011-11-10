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
	cout << x;
	return x;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	OrderedCollection c1(10);
	OrderedCollection c2(999);
	OrderedCollection c3(c2);

	c3.doFunc(*printInt);
	return 0;
}
