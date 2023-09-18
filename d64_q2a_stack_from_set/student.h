#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  CP::stack<T> s;
  // std::cout << "a";
  // int range = last-first;
  // T *newData = new T[range];
  int cap = 1;
  mData = new T[cap]();
  mCap = cap;
  mSize = 0;

  for(auto it=first;it!=last;it++) {
    s.push(*it);
    // this->push(*it);
  }
  while(!s.empty()) {
    // this->push(s.top());
    if (mSize + 1 > mCap) 
      expand(mCap * 2);
    mData[mSize] = s.top();
    mSize++;
    s.pop();
  }
}

#endif
