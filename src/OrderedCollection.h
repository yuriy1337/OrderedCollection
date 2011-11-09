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
	int& operator[](int);

	bool isEmpty();
	int size();
	int basicSize();

	OrderedCollection& insertAt(int,int);

protected:
	int firstIndex_;
	int lastIndex_;
	int size_;
	int basicSize_;
	int * array_;

private:
	bool shift(int dir, int index);
};

#endif /* ORDEREDCOLLECTION_H_ */
