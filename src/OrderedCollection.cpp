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
	for (int var = 0; var < basicSize_; ++var) {
		array_[var] = 0;
	}
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
		return array_[firstIndex_];
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

OrderedCollection& OrderedCollection::insertAt(int i, int x){
	if (i < 0 || i + firstIndex_ > lastIndex_) {
		std::cout << "Index of out bounds" << std::endl;
		return *this;
	}
	if(array_[i] == 0){
		array_[i] = x;
	}
	else{
		bool shifted = false;
		if(i < basicSize_/2)
			shifted = shift(-1,i);
		else
			shifted = shift(-1,i);
		if(shifted){
			array_[i] = x;
		}
	}
	return *this;
}


bool OrderedCollection::shift(int dir, int index){
	if(dir == -1){	//left
		if(array_[0] == 0){
			for (int var = 1; var + firstIndex_ <= basicSize_; ++var) {
				array_[var - 1] = array_[var];
			}
		}
		else{
			return false;
		}
	}
	else
	if(dir == 1){	//right
		if(array_[0] == 0){
			for (int var = basicSize_ - 1; var >= index + firstIndex_; --var) {
				array_[var + 1] = array_[var];
			}
		}
		else{
			return false;
		}
	}
	return true;
}
