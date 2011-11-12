/*
 * OrderedCollection.cpp
 *
 *  Created on: Nov 9, 2011
 *      Author: myronche
 */

#include "OrderedCollection.h"
#include <iostream>
#include <time.h>

const static int zero = 0;
/*
 * Constructors
 */
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

OrderedCollection::OrderedCollection(int x) {
	firstIndex_ = 2;
	lastIndex_ = 2;
	size_ = 0;
	basicSize_ = 8;
	array_ = new int[8];
	for (int var = 0; var < basicSize_; ++var) {
		array_[var] = 0;
	}
	insertAt(1,x);
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

/*
 * Destructor
 */
OrderedCollection::~OrderedCollection() {
	delete[] array_;
}

/*
 * Overloading operators
 */
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

/*
 * public functions
 */
int & OrderedCollection::operator[](int index){
	if (index < 1 || index + firstIndex_ > lastIndex_) {
		std::cout << "Index of out bounds" << std::endl;
	}
	else{
		return array_[index + firstIndex_ - 1];
	}
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
	if (i < 1 || i + firstIndex_ > lastIndex_ + 1) {
		std::cout << "Index of out bounds" << std::endl;
		return *this;
	}
	i--; /*
			to correct for the offset, since OrderedCollection
			starts at 1 instead of 0;
	 */

	if(array_[firstIndex_ + i] == 0 && firstIndex_ + size_ != basicSize_){
		array_[firstIndex_ + i] = x;
		lastIndex_++;
	}
	else{
		if(firstIndex_ + i - 1 >= 0 && array_[firstIndex_ + i - 1] == 0){
			array_[firstIndex_ + i - 1] = x;
			firstIndex_--;
		}
		else{
			bool shifted = false;
			if(i < basicSize_/2){
				shifted = shift(-1,1,i);
				if(shifted){
					firstIndex_--;
					lastIndex_--;
				}
			}
			if(!shifted && firstIndex_ > i){
				shifted = shift(1,i,size_);
				if(shifted){
					firstIndex_++;
					lastIndex_++;
				}
			}
			if(!shifted){
				if(firstIndex_ > i){
					shifted = makeRoomAtFirst();
				}
				else{
					if(basicSize_ - size_ >= lastIndex_ - i)
						shifted = makeRoomAtLast();
				}
			}
			if(shifted){
				array_[firstIndex_ + i] = x;
				lastIndex_++;
			}
			else{
				grow();
				if(firstIndex_ + i - 1 >= 0 && array_[firstIndex_ + i - 1] == 0){
					array_[firstIndex_ + i - 1] = x;
					firstIndex_--;
				}
				else
				if(array_[firstIndex_ + i] == 0 && firstIndex_ + size_ != basicSize_){
					array_[firstIndex_ + i] = x;
					lastIndex_++;
				}
				else{
					if(i < basicSize_/2){
						shifted = shift(-1,1,i);
						firstIndex_--;
						lastIndex_--;
					}
					else{
						shifted = shift(1,i,size_);
						firstIndex_++;
						lastIndex_++;
					}
					}
					if(shifted){
						array_[firstIndex_ + i] = x;
						lastIndex_++;
					}
				}
			}
		}
	}
	size_++;
	return *this;
}

OrderedCollection& OrderedCollection::insert(int x){
	srand ( time(NULL) );
	int pos = 1;
	if(size_ != 0)
		pos = (rand() % size_) + 1;
	return insertAt(pos, x);
}

int OrderedCollection::find(int x){
	for (int var = firstIndex_; var < lastIndex_ + 1; ++var) {
		if(array_[var] == x)
			return var - firstIndex_ + 1;
	}
	return 0;
}

OrderedCollection& OrderedCollection::removeAt(int i){
	if (i < 1 || i + firstIndex_ > lastIndex_ + 1) {
		std::cout << "Index of out bounds" << std::endl;
		return *this;
	}
	i--;	//adjust for smalltalk-like arrays starting with one
	array_[firstIndex_ + i] = 0;
	if(i == 0){
		firstIndex_++;
	}
	else{
		if(i == size_ - 1){
			lastIndex_--;
		}else{
		if(i < size_/2){
			shift(1,1,i);
			firstIndex_++;
		}
		else{
			shift(-1,i,size_);
			lastIndex_--;
		}
		}
	}
	size_--;
	return *this;
}

OrderedCollection& OrderedCollection::doFunc(int (*fn)(int)){
	for (int var = firstIndex_; var < lastIndex_; ++var) {
		array_[var] = fn(array_[var]);
	}
	return *this;
}

/*
 * Protected Functions
 */

bool OrderedCollection::makeRoomAtFirst(){
	if(array_[basicSize_ - 1] == 0){
		int count = 0;
		while(array_[basicSize_ - 1] == 0){
			for (int var = basicSize_ -1; var >= 0; --var) {
				if(var!= 0)
					array_[var] = array_[var - 1];
				else
					array_[var] = 0;
			}
			count++;
			firstIndex_++;
			lastIndex_++;
		}

	}
	else{
		return false;
	}

	return true;
}

bool OrderedCollection::makeRoomAtLast(){
	if(array_[0] == 0){
		int count = 0;
		while(array_[0] == 0){
			for (int var = 0; var < basicSize_; ++var) {
				array_[var] = array_[var + 1];
			}
			count++;
			firstIndex_--;
			lastIndex_--;
		}
	}
	else{
		return false;
	}
	return true;
}

void OrderedCollection::grow(){
	int * new_arr = new int[basicSize_ * 2];
	int counter = 0;
	int new_start = (basicSize_ * 2)/4;
	for (int var = firstIndex_; var < lastIndex_; ++var) {
		new_arr[new_start + counter] = array_[var];
		counter++;
	}
	delete[] array_;
	array_ = new_arr;
	firstIndex_ =  new_start;
	lastIndex_ = firstIndex_ + size_;
	basicSize_ = basicSize_ * 2;
	/*
	 * Just because
	 * (づ｡◕‿‿◕｡)づ
	 */
}

/*
 * Private Functions
 */
bool OrderedCollection::shift(int dir, int start, int end){
	if(dir == -1){	//left
		if(array_[0] == 0){
			for (int var = firstIndex_ + start - 1; var <= firstIndex_ + end; ++var) {
				array_[var - 1] = array_[var];
			}
		}
		else{
			return false;
		}
	}
	else
	if(dir == 1){	//right
		if(firstIndex_+end != basicSize_ && array_[firstIndex_+end] == 0){
			for (int var = firstIndex_ + end - 1; var >= 0 + start; --var) {
				array_[var + 1] = array_[var];
			}
		}
		else{
			return false;
		}
	}
	return true;
}

void OrderedCollection::print(){
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "[";
	for (int var = 0; var < basicSize_; ++var) {
		std::cout << array_[var] << "\t";
	}
	std::cout << "]";
	std::cout << std::endl;
	std::cout << "[";
		for (int var = 0; var < basicSize_; ++var) {
			std::cout << var << "\t";
		}
	std::cout << "]" << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
}


