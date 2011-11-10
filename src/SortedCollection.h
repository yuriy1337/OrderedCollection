/*
 * SortedCollection.h
 *
 *  Created on: Nov 9, 2011
 *      Author: Yuriy
 */

#ifndef SORTEDCOLLECTION_H_
#define SORTEDCOLLECTION_H_

#include "OrderedCollection.h"

class SortedCollection: public OrderedCollection {
public:
	SortedCollection();
	SortedCollection(int);
	SortedCollection(const OrderedCollection&);
	SortedCollection(const SortedCollection&);
	virtual ~SortedCollection();

	OrderedCollection& insertAt(int,int);
	OrderedCollection& insert(int);

private:
	void quickSort(int, int);
};

#endif /* SORTEDCOLLECTION_H_ */
