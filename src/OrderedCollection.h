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
	OrderedCollection(int);
	OrderedCollection(const OrderedCollection&);
	virtual ~OrderedCollection();

	OrderedCollection& operator=(const OrderedCollection&);
	int& operator[](int);

	bool isEmpty();
	int size();
	int basicSize();
	int find(int);

	OrderedCollection& insertAt(int,int);
	OrderedCollection& insert(int);
	OrderedCollection& removeAt(int);
	OrderedCollection& doFunc(int(*fn)(int));	//do is a key word, used for looping

	void print();

protected:
	int firstIndex_;
	int lastIndex_;
	int size_;
	int basicSize_;
	int * array_;

	bool makeRoomAtFirst(int);
	bool makeRoomAtLast(int);
	void grow();

private:
	bool shift(int dir, int index);

};

#endif /* ORDEREDCOLLECTION_H_ */
