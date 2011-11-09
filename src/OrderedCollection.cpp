/*
 * OrderedCollection.cpp
 *
 *  Created on: Nov 9, 2011
 *      Author: myronche
 */

#include "OrderedCollection.h"

OrderedCollection::OrderedCollection() {
	firstIndex = 2;
	lastIndex = 2;
	size = 0;
	basicSize = 8;
	array = new int[8];
}

OrderedCollection::OrderedCollection(const OrderedCollection& oc) {
	firstIndex = oc.firstIndex;
	lastIndex = oc.lastIndex;
	size = oc.size;
	basicSize = oc.basicSize;
	array = new int[basicSize];
	for (int var = 0; var < basicSize; ++var) {
		array[var] = oc.array[var];
	}
}

OrderedCollection::~OrderedCollection() {
	delete[] array;
}

OrderedCollection & OrderedCollection::operator =(const OrderedCollection& rhs){
	if(this != &rhs){
		firstIndex = rhs.firstIndex;
		lastIndex = rhs.lastIndex;
		size = rhs.size;
		basicSize = rhs.basicSize;
		delete[] array;
		array = new int[basicSize];
		for (int var = 0; var < basicSize; ++var) {
			array[var] = rhs.array[var];
		}
	}
	return *this;
}
