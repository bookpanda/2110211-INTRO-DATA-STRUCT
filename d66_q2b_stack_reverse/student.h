#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// write your code here
	if(first > last) return;
	first = std::min(mSize-1, first);
	last = std::min(mSize-1, last);
	int sz = (last-first+1)/2;

	for(int i=0;i<sz;i++) {
		// std::cout << "id " << mSize-1-first-i << ", " << mSize-1-last+i << "\n";
		// std::cout << "swap " << mData[mSize-1-first-i] << ", " << mData[mSize-1-last+i] << "\n";
		std::swap(mData[mSize-1-first-i], mData[mSize-1-last+i]);
	}
}

#endif
