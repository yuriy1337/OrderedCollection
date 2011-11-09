/*
 * OrderedCollection.h
 *
 *  Created on: Nov 9, 2011
 *      Author: myronche
 */

#ifndef ORDEREDCOLLECTION_H_
#define ORDEREDCOLLECTION_H_

class OrderedCollection {
public:
	OrderedCollection();
	OrderedCollection(const OrderedCollection&);
	virtual ~OrderedCollection();

	OrderedCollection& operator=(const OrderedCollection&);

protected:
	int firstIndex;
	int lastIndex;
	int size;
	int basicSize;
	int * array;
};

#endif /* ORDEREDCOLLECTION_H_ */
