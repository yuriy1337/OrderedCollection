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

OrderedCollection::~OrderedCollection() {
	// TODO Auto-generated destructor stub
}
