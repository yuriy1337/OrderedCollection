/*
 * SortedCollection.cpp
 *
 *  Created on: Nov 9, 2011
 *      Author: Yuriy
 */

#include "SortedCollection.h"
#include <iostream>
/*
 * Constructors
 */
SortedCollection::SortedCollection()
: OrderedCollection()
{
	std::cout << "in constructor for SortedCollection" << std::endl;
}

SortedCollection::SortedCollection(int x)
: OrderedCollection(x)
{
}

SortedCollection::SortedCollection(const OrderedCollection& oc)
: OrderedCollection(oc)
{
	quickSort(firstIndex_,firstIndex_+size_);
}

SortedCollection::SortedCollection(const SortedCollection& sc)
: OrderedCollection(sc)
{
}

/*
 * Destructor
 */
SortedCollection::~SortedCollection() {
	delete[] array_;
}

SortedCollection& SortedCollection::insertAt(int,int){
	std::cout << "Cannot InsertAt for an OrderedCollection" << std::endl;
	return *this;
}

SortedCollection& SortedCollection::insert(int x){
	if(size_ > 0){
		for (int var = firstIndex_; var <= basicSize_; ++var) {
			if(array_[var] > x){
				((OrderedCollection*)this)->insertAt(var - firstIndex_ + 1,x);
				break;
			}
		}
	}
	else{
		((OrderedCollection*)this)->insertAt(1,x);
	}
	return *this;
}

SortedCollection& SortedCollection::doFunc(int(*fn)(int)){
	((OrderedCollection*)this)->doFunc(fn);
	quickSort(firstIndex_,firstIndex_+size_);
}

void SortedCollection::quickSort(int left, int right) {
	int * arr = array_;
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}
