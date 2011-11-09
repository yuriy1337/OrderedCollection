/*
 * OrderedCollection.cpp
 *
 *  Created on: Nov 9, 2011
 *      Author: myronche
 */

#include "OrderedCollection.h"
#include <iostream>

OrderedCollection::OrderedCollection() {
	firstIndex_ = 2;
	lastIndex_ = 2;
	size_ = 0;
	basicSize_ = 8;
	array_ = new int[8];
}

OrderedCollection::OrderedCollection(const OrderedCollection& oc) {
	firstIndex_ = oc.firstIndex_;
	lastIndex_ = oc.lastIndex_;
	size_ = oc.size_;
	basicSize_ = oc.basicSize_;
	array_ = new int[basicSize_];
	for (int var = 0; var < basicSize_; ++var) {
		array_[var] = oc.array_[var];
	}
}

OrderedCollection::~OrderedCollection() {
	delete[] array_;
}

OrderedCollection & OrderedCollection::operator =(const OrderedCollection& rhs){
	if(this != &rhs){
		firstIndex_ = rhs.firstIndex_;
		lastIndex_ = rhs.lastIndex_;
		size_ = rhs.size_;
		basicSize_ = rhs.basicSize_;
		delete[] array_;
		array_ = new int[basicSize_];
		for (int var = 0; var < basicSize_; ++var) {
			array_[var] = rhs.array_[var];
		}
	}
	return *this;
}

int & OrderedCollection::operator[](int index){
	if (index < 0 || index + firstIndex_ > lastIndex_) {
		std::cout << "Index of out bounds" << std::endl;
	}
	return array_[index + firstIndex_];
}

bool OrderedCollection::isEmpty(){
	return (size_ == 0);
}

int OrderedCollection::size(){
	return size_;
}

int OrderedCollection::basicSize(){
	return basicSize_;
}
